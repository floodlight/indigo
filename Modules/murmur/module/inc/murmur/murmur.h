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

/*
 * Port of MurmurHash3 (public domain) to C.
 * http://code.google.com/p/smhasher/source/browse/trunk/MurmurHash3.cpp
 */

#ifndef MURMUR_MURMUR_H
#define MURMUR_MURMUR_H

#include <stdint.h>

static inline uint32_t
murmur_rotl32(uint32_t x, int8_t r)
{
    return (x << r) | (x >> (32 - r));
}

static inline uint32_t
murmur_fmix(uint32_t h)
{
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;
    return h;
}

static inline uint32_t
murmur_hash(const void *key, int len, uint32_t seed)
{
    const uint8_t *data = key;
    const int nblocks = len / 4;

    uint32_t h1 = seed;

    const uint32_t c1 = 0xcc9e2d51;
    const uint32_t c2 = 0x1b873593;

    const uint32_t *blocks = (const uint32_t *)(data + nblocks*4);

    const uint8_t* tail;
    uint32_t k1;

    int i;
    for(i = -nblocks; i; i++)
    {
        uint32_t k1 = blocks[i];

        k1 *= c1;
        k1 = murmur_rotl32(k1,15);
        k1 *= c2;

        h1 ^= k1;
        h1 = murmur_rotl32(h1,13);
        h1 = h1*5+0xe6546b64;
    }

    tail = (const uint8_t*)(data + nblocks*4);
    k1 = 0;

    switch(len & 3)
    {
        case 3: k1 ^= tail[2] << 16;
        case 2: k1 ^= tail[1] << 8;
        case 1: k1 ^= tail[0];
                k1 *= c1; k1 = murmur_rotl32(k1,15); k1 *= c2; h1 ^= k1;
    };

    h1 ^= len;

    h1 = murmur_fmix(h1);

    return h1;
}

#endif
