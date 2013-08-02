#!/usr/bin/env python
#################################################################
#
#        Copyright 2013, Big Switch Networks, Inc. 
# 
# Licensed under the Eclipse Public License, Version 1.0 (the
# "License"); you may not use this file except in compliance
# with the License. You may obtain a copy of the License at
# 
#        http://www.eclipse.org/legal/epl-v10.html
# 
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
# either express or implied. See the License for the specific
# language governing permissions and limitations under the
# License.
#
################################################################

# This script builds each target for multiple toolchains and runs all unit tests.
import sys
import subprocess
import os

os.chdir(os.path.join(os.path.dirname(__file__), ".."))

log = sys.stderr.write
dev_null = open('/dev/null', 'r')

CCACHE_DIR = '/usr/lib/ccache'
if os.path.isdir(CCACHE_DIR):
    log("Enabling ccache\n")
    os.environ['PATH'] = ':'.join([CCACHE_DIR, os.environ['PATH']])
else:
    log("Install ccache for faster builds\n")

os.environ['BUILDER'] = os.path.join(os.getcwd(), 'Builder', 'unix')

try:
    os.mkdir('testlogs')
except:
    pass

# TODO add more default toolchains
BUILDS = []
def build(path, toolchains=['gcc-local']):
    BUILDS.append({ 'path' : path, 'toolchains' : toolchains })

TESTS = []
def test(name, cmd):
    TESTS.append({ 'name' : name, 'cmd' : cmd })

# Builds
build('targets/hindex-benchmark')

# Unit tests
utestsdir = 'targets/utests'
utests = [
    'AIM',
    'BigData/BigList',
    'Indigo/Configuration',
    'Indigo/indigo',
    'Indigo/OFConnectionManager',
    'Indigo/OFStateManager',
    'Indigo/SocketManager',
    'loci',
    'locitest',
    'hindex',
]
for utest in utests:
    build(os.path.join(utestsdir, utest), toolchains=['gcc-local'])
    test(utest, "make -C %s" % os.path.join(utestsdir, utest))

if sys.stderr.isatty():
    RED = "\x1B[31m"
    GREEN = "\x1B[32m"
    NORM = "\x1B[39m"
else:
    RED = ""
    GREEN = ""
    NORM = ""

failures = 0

for build in BUILDS:
    for toolchain in build['toolchains']:
        log("Building %s (%s) ... " % (build['path'], toolchain))
        cmd = "make -C %s clean TOOLCHAIN=%s && time make -j8 -C %s all TOOLCHAIN=%s" % (build['path'], toolchain, build['path'], toolchain)
        logfile_path = os.path.join(build['path'], 'build.%s.log' % toolchain)
        with open(logfile_path, 'w') as logfile:
            ret = subprocess.call(cmd, shell=True, stdin=dev_null, stdout=logfile, stderr=logfile)
        if ret == 0:
            log(GREEN + "OK" + NORM + "\n")
        else:
            failures += 1
            log(RED + "FAIL" + NORM + "\n")
            log("Build log is in %s\n" % logfile_path)
            log("To reproduce: %s\n" % cmd)

for test in TESTS:
    log("Testing %s ... " % test['name'])
    logfile_path = os.path.join('testlogs', '%s.log' % test['name'].replace('/', '.'))
    with open(logfile_path, 'w') as logfile:
        ret = subprocess.call(test['cmd'], shell=True, stdin=dev_null, stdout=logfile, stderr=logfile)
    if ret == 0:
        log(GREEN + "OK" + NORM + "\n")
    else:
        failures += 1
        log(RED + "FAIL" + NORM + "\n")
        log("Test log is in %s\n" % logfile_path)
        log("To reproduce: %s\n" % test['cmd'])

if failures == 0:
    log(GREEN + "PASSED" + NORM + "\n")
    sys.exit(0)
else:
    log(RED + "FAILED" + NORM + "\n")
    sys.exit(1)

