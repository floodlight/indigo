#!/usr/bin/python
################################################################
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

###############################################################################
#
# This is a general purpose tool to facilitate code generation.
# Many basic autogeneration scripts read from a file and
# print the new file to stdout, usually of the form:
# $(TOOL) srcfile > srcfile.
#
# While this is easy on the script generator,
# We don't want to update source files and cause unecessary recompilation
# unless they change.
#
# This tool diffs the output of the tool with the source file and
# only updates the file if changes were detected.
#
################################################################################
import os
import sys
import subprocess

def write_on_diff(fname, new, msg=True):
    existing = None
    if os.path.exists(fname):
        with open(fname, "r") as f:
            existing=f.read()

    if new == existing:
        if msg:
            print "%s: no changes." % fname
    else:
        if msg:
            print "%s: updated." % fname
        with open(fname, "w") as f:
            f.write(new)


if __name__ == "__main__":

    if len(sys.argv) == 1 or len(sys.argv) == 2:
        raise Exception("usage: filename command [args, ...]")

    # the file being generated
    fname = sys.argv[1];

    # the command that generates it
    cmd = sys.argv[2:]

    p = subprocess.Popen(cmd, stdout=subprocess.PIPE)
    out, err = p.communicate()

    write_on_diff(fname, out);
