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

/******************************************************************************
 *
 * biglist_sort.c
 *
 *****************************************************************************/
#include "biglist_int.h"
#include <stdlib.h>


/*****************************************************************************
 *
 * This mergesort implementation was derived from open code provided at
 * http://www.chiark.greenend.org.uk/~sgtatham/algorithms/listsort.html.
 *
 * The copyright notice and permission for this derivative
 * work are incorporated herein:
 *
 *****************************************************************************
 * Copyright 2001 Simon Tatham.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL SIMON TATHAM BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *****************************************************************************/

biglist_t*
biglist_sort(biglist_t* bl, biglist_compare_f cmp)
{
    int listSize=1;
    int numMerges;
    int leftSize;
    int rightSize;

    biglist_t* tail;
    biglist_t* left;
    biglist_t* right;
    biglist_t* next;

    if (bl == NULL || bl->next == NULL) {
        return bl;
    }

    do {

        numMerges=0;
        left=bl;
        bl = NULL;
        tail = NULL;

        while (left) {

            numMerges++;
            right=left;
            leftSize=0;
            rightSize=listSize;

            // Cut list into two halves (but don't overrun)
            while (right && leftSize < listSize) {
                ++leftSize;
                right = right->next;
            }

            // Run through the lists appending onto what we have so far.
            while (leftSize > 0 || ( rightSize > 0 && right) ) {
                // Left empty, take right OR Right empty, take left, OR compare.
                if (!leftSize) {
                    next=right;
                    right=right->next;
                    rightSize--;
                }
                else if (!rightSize || !right)  {
                    next=left;
                    left=left->next;
                    leftSize--;
                }
                else if (cmp(left->data,right->data) < 0) {
                    next=left;
                    left=left->next;
                    leftSize--;
                }
                else {
                    next=right;
                    right=right->next;
                    rightSize--;
                }
                // Update pointers to keep track of where we are:
                if (tail) {
                    tail->next=next;
                } else {
                    bl=next;
                }
                // Sort prev pointer
                next->previous=tail;
                tail=next;
            }
            // Right is now AFTER the list we just sorted, so start the next sort there.
            left=right;
        }
        // Terminate the list, double the list-sort size.
        tail->next=0;
        listSize<<=1;

    } while ( numMerges >1 ); // If we only did one merge, then we just sorted the whole list.
    return bl;
}


