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
 * Bitmap operations.
 *
 * @file
 * @addtogroup aim-bitmap
 * @{
 *
 *
 *****************************************************************************/
#ifndef __AIM_BITMAP_H__
#define __AIM_BITMAP_H__

#include <AIM/aim_config.h>

/** atomic bitmap storage type. */
typedef uint32_t aim_bitmap_word_t;

/** All bitmaps must contain this structure */
typedef struct aim_bitmap_hdr_s {
    /** The number of words in this bitmap */
    int wordcount;
    /** bitmap words */
    aim_bitmap_word_t* words;
    /** Maximum allowable bit */
    int maxbit;
    /** Indicates AIM allocated this bitmap structure */
    int allocated;
} aim_bitmap_hdr_t;

/** The number of bits in each bitmap_word */
#define AIM_BITMAP_BITS_PER_WORD (sizeof(aim_bitmap_word_t)*8) /* use CHAR_BITS here */

/** The number of words required to store a given bitcount */
#define AIM_BITMAP_WORD_COUNT(_bitcount)                        \
    ( ((_bitcount)/AIM_BITMAP_BITS_PER_WORD) +                  \
      ( ((_bitcount) % AIM_BITMAP_BITS_PER_WORD) ? 1 : 0) )

/** A dynamically allocated bitmap. */
typedef struct aim_bitmap_t {
    /** bitmap hdr */
    aim_bitmap_hdr_t hdr;
} aim_bitmap_t;


/** Define a static-sized bitmap */
#define AIM_STATIC_BITMAP_DEFINE(_bitcount)                             \
    typedef struct aim_bitmap##_bitcount##_s {                          \
        aim_bitmap_hdr_t hdr;                                           \
        aim_bitmap_word_t words[AIM_BITMAP_WORD_COUNT(_bitcount)];      \
    } aim_bitmap##_bitcount##_t

/** 32 bit bitmap */
AIM_STATIC_BITMAP_DEFINE(32);
/** 64 bit bitmap */
AIM_STATIC_BITMAP_DEFINE(64);
/** 96 bit bitmap */
AIM_STATIC_BITMAP_DEFINE(96);
/** 128 bit bitmap */
AIM_STATIC_BITMAP_DEFINE(128);
/** 256 bit bitmap */
AIM_STATIC_BITMAP_DEFINE(256);

/** The number of bits in a given bitmap array */
#define AIM_BITMAP_ARRAY_BITCOUNT(_a)                   \
    (AIM_ARRAYSIZE(_a) * AIM_BITMAP_BITS_PER_WORD)

/** Initialize a static bitmap structure */
#define AIM_BITMAP_INIT(_name, _count)                          \
    do {                                                        \
        AIM_MEMSET(_name, 0, sizeof(*(_name)));                 \
        (_name)->hdr.maxbit = _count;                           \
        (_name)->hdr.words = (_name)->words;                    \
        (_name)->hdr.wordcount = AIM_ARRAYSIZE((_name)->words); \
    } while(0)


/**
 * @brief Allocate a dynamic bitmap structure.
 * @param [out] rv Receives the new bitmap structure.
 * If rv is NULL, a new structure will be allocated.
 * @param bitcount The number of bits required.
 * @returns A pointer to the new bitmap structure.
 */
aim_bitmap_t* aim_bitmap_alloc(aim_bitmap_t* rv, int bitcount);

/**
 * @brief Free a bitmap structure.
 * @param bmap The bitmap structure to free.
 */
void aim_bitmap_free(aim_bitmap_t* bmap);

/** Get a word from the give bitmap header */
#define AIM_BITMAP_HDR_WORD_GET(_hdr, _word)    \
    ( (_hdr)->words[_word] )

/** Get the word containing the given bit */
#define AIM_BITMAP_HDR_BIT_WORD(_hdr, _bit)            \
    ( (_hdr)->words[_bit/AIM_BITMAP_BITS_PER_WORD] )

/** Get the bit's position in its target word */
#define AIM_BITMAP_BIT_POS(_bit)                        \
    ( (1L << (_bit % AIM_BITMAP_BITS_PER_WORD)) )


/*
 * All bitmap structures contain the bitmap header. These inlines operate
 * on that header directly.
 */

/**
 * @brief Set a bit in the bitmap.
 * @param hdr The bitmap header.
 * @param bit The bit number to set.
 */
static inline void
aim_bitmap_set(aim_bitmap_hdr_t* hdr, int bit)
{
    AIM_BITMAP_HDR_BIT_WORD(hdr, bit) |= AIM_BITMAP_BIT_POS(bit);
}

/**
 * @brief Clear a bit in the bitmap.
 * @param hdr The bitmap header.
 * @param bit The bit number to clear.
 */
static inline void
aim_bitmap_clr(aim_bitmap_hdr_t* hdr, int bit)
{
    AIM_BITMAP_HDR_BIT_WORD(hdr, bit) &= ~(AIM_BITMAP_BIT_POS(bit));
}

/**
 * @brief Modify a bit in the bitmap.
 * @param hdr The bitmap header.
 * @param bit The bit number to modify.
 * @param value The bit's new value.
 */
static inline void
aim_bitmap_mod(aim_bitmap_hdr_t* hdr, int bit, int value)
{
    if(value) {
        aim_bitmap_set(hdr, bit);
    }
    else {
        aim_bitmap_clr(hdr, bit);
    }
}
/**
 * @brief Get the value of a bit in the bitmap.
 * @param hdr The bitmap header.
 * @param bit The bit number.
 */
static inline int
aim_bitmap_get(aim_bitmap_hdr_t* hdr, int bit)
{
    return (AIM_BITMAP_HDR_BIT_WORD(hdr,bit) & AIM_BITMAP_BIT_POS(bit)) ? 1 : 0;
}

/**
 * @brief Set all bits in the given bitmap.
 * @param hdr The bitmap header.
 */
static inline void
aim_bitmap_set_all(aim_bitmap_hdr_t* hdr)
{
    AIM_MEMSET(hdr->words, 0xFF, hdr->wordcount*sizeof(aim_bitmap_word_t));
}
/**
 * @brief Clear all bits in the given bitmap.
 * @param hdr The bitmap header.
 */
static inline void
aim_bitmap_clr_all(aim_bitmap_hdr_t* hdr)
{
    AIM_MEMSET(hdr->words, 0x0, hdr->wordcount*sizeof(aim_bitmap_word_t));
}
/**
 * @brief Get the given 32bit word from the bitmap.
 * @param hdr The bitmap header.
 * @param word The 32bit word index.
 */
static inline uint32_t
aim_bitmap_word_get32(aim_bitmap_hdr_t* hdr, int word)
{
    return hdr->words[word];
}
/**
 * @brief Set the given 32bit word in the bitmap.
 * @param hdr The bitmap header.
 * @param word The 32bit word index.
 * @param value The new value.
 */
static inline void
aim_bitmap_word_set32(aim_bitmap_hdr_t* hdr, int word, uint32_t value)
{
    hdr->words[word] = value;
}

/*
 * These macros can operate directly on any bitmap structure
 * containing the proper header.
 */

/** Set a bit */
#define AIM_BITMAP_SET(_bmap, _bit)             \
    aim_bitmap_set(&((_bmap)->hdr), _bit);

/** Clear a bit */
#define AIM_BITMAP_CLR(_bmap, _bit)             \
    aim_bitmap_clr(&((_bmap)->hdr), _bit)

/** Modify a bit */
#define AIM_BITMAP_MOD(_bmap, _bit, _value)     \
    aim_bitmap_mod(&((_bmap)->hdr), _bit, _value)

/** Get a bit */
#define AIM_BITMAP_GET(_bmap, _bit)             \
    aim_bitmap_get(&((_bmap)->hdr), _bit)

/** Set all bits */
#define AIM_BITMAP_SET_ALL(_bmap)               \
    aim_bitmap_set_all(&((_bmap)->hdr))

/** Clear all bits */
#define AIM_BITMAP_CLR_ALL(_bmap)               \
    aim_bitmap_clr_all(&((_bmap)->hdr))

/** Get a 32 bit word at the given offset */
#define AIM_BITMAP_WORD_GET32(_bmap, _word)             \
    aim_bitmap_word_get32(&((_bmap)->hdr), _word)
/** Set a 32 bit word at the given offset */
#define AIM_BITMAP_WORD_SET32(_bmap, _word, _value) \
    aim_bitmap_word_set32(&((_bmap)->hdr), _word, _value)

/** Iterate through all bits set in the bitmap */
#define AIM_BITMAP_ITER(_bmap, _bit)                   \
    for(_bit = 0; _bit <= (_bmap)->hdr.maxbit; _bit++) \
        if(AIM_BITMAP_GET(_bmap, _bit))








#endif /* __AIM_BITMAP_H__ */
/* @}*/
