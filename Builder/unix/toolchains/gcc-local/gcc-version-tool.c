/****************************************************************
 *
 *        Copyright 2013, Big Switch Networks, Inc. 
 * 
 * Licensed under the Eclipse Public License, Version 1.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 * 
 *        http://www.eclipse.org/legal/epl-v10.html
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the
 * License.
 *
 ****************************************************************/

/**
 * Getting just the GCC version number from a command line invocation
 * (like gcc --version) is difficult because of the abitrary output
 *
 * If no options are given, this tool prints the current GCC version number.
 * If an operator is given, it will tell you whether the expression
 * related to the operator is true or false.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int
result__(int b)
{
    printf("%s\n", (b) ? "true" : "false");
    return b;
}

int main(int argc, char* argv[])
{
    int gcc_version =
        __GNUC__ * 1000 +
        __GNUC_MINOR__ * 100 +
        __GNUC_PATCHLEVEL__;

    /* Default check is greater-than */
    char* operator;
    char* cvs;
    int cv;

    if(argc == 1) {
        printf("%d\n", gcc_version);
        return 0;
    }
    else if(argc == 2) {
        /* default check is greater-than-or-equal */
        operator = "gte";
        cvs = argv[1];
    }
    else if(argc == 3) {
        operator = argv[1];
        cvs = argv[2];
    }
    else {
        printf("invalid arguments.");
        return -1;
    }

    cv = atoi(cvs);

    if(!strcmp(operator, "gte")) {
        return result__(gcc_version >= cv);
    }
    if(!strcmp(operator, "gt")) {
        return result__(gcc_version > cv);
    }
    if(!strcmp(operator, "lte")) {
        return result__(gcc_version <= cv);
    }
    if(!strcmp(operator, "lt")) {
        return result__(gcc_version < cv);
    }
    if(!strcmp(operator, "eq") || !strcmp(operator, "==") || !strcmp(operator, "-")) {
        return result__(gcc_version == cv);
    }
}




