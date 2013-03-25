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

/**************************************************************************//**
 *
 * @file
 * @brief AIM Mapping
 *
 *****************************************************************************/
#ifndef __AIM_MAP_H__
#define __AIM_MAP_H__


/**
 * Map a string to an integer.
 */
typedef struct aim_map_si_t {
    /** String value */
    const char* s;
    /** Integer value */
    int         i;
} aim_map_si_t;

/**
 * @brief Map a string to an integer.
 * @param [out] rv The mapped integer value.
 * @param s The string to map.
 * @param maps The map table.
 * @param count The number of entries in the map table.
 *
 * @returns 1 if the mapping was successful.
 * @returns 0 if the mapping failed.
 *
 * @note If count is 0, maps is assumed to be terminated with a null entry.
 */
int aim_map_si_s(int* rv, const char* s, aim_map_si_t* maps, unsigned int count);

/**
 * @brief Map an integer to a string.
 * @param [out] rv The mapped string value.
 * @param i The integer to map.
 * @param maps The map table.
 * @param count The number of entries in the map table.
 *
 * @returns 1 if the mapping was successful.
 * @returns 0 if the mapping failed.
 *
 * @note If count is 0, maps is assumed to be terminated with a null entry.
 */
int aim_map_si_i(const char** rv, int i, aim_map_si_t* maps,
                 unsigned int count);






#endif /* __AIM_MAP_H__ */
