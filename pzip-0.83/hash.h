#ifndef HASH_H
#define HASH_H

#include "inc.h"
#include "context.h"

Context* hash_Find_Context_02(   Suffix suffix   );
void     hash_Note_Context_02(   Context* context,   Suffix suffix   );
void     hash_Drop_Context_02(   Context* context   );

Context* hash_Find_Context_03(   Suffix suffix   );
void     hash_Note_Context_03(   Context* context,   Suffix suffix   );
void     hash_Drop_Context_03(   Context* context   );

Context* hash_Find_Context_04(   Suffix suffix   );
void     hash_Note_Context_04(   Context* context,   Suffix suffix   );
void     hash_Drop_Context_04(   Context* context   );

Context* hash_Find_Context_05(   Suffix suffix   );
void     hash_Note_Context_05(   Context* context,   Suffix suffix   );
void     hash_Drop_Context_05(   Context* context   );

Context* hash_Find_Context_08(   Suffix suffix   );
void     hash_Note_Context_08(   Context* context,   Suffix suffix   );
void     hash_Drop_Context_08(   Context* context   );

Context* hash_Find_Context_12(   Suffix suffix   );
void     hash_Note_Context_12(   Context* context,   Suffix suffix   );
void     hash_Drop_Context_12(   Context* context   );

Context* hash_Find_Context_16(   Suffix suffix   );
void     hash_Note_Context_16(   Context* context,   Suffix suffix   );
void     hash_Drop_Context_16(   Context* context   );

#define HASH_SLOTS_02 (1 << 16)
#define HASH_MASK_02  (HASH_SLOTS_02 -1)

#define HASH_SLOTS_03 (1 << 18)
#define HASH_MASK_03  (HASH_SLOTS_03 -1)

#define HASH_SLOTS_04 (1 << 19)
#define HASH_MASK_04  (HASH_SLOTS_04 -1)

#define HASH_SLOTS_05 (1 << 22)
#define HASH_MASK_05  (HASH_SLOTS_05 -1)

#define HASH_SLOTS_08 (1 << 21)
#define HASH_MASK_08  (HASH_SLOTS_08 -1)

#define HASH_SLOTS_12 (1 << 19)
#define HASH_MASK_12  (HASH_SLOTS_12 -1)

#define HASH_SLOTS_16 (1 << 19)
#define HASH_MASK_16  (HASH_SLOTS_16 -1)

#ifdef __GNUC__
extern Context* hashtab_05[ HASH_SLOTS_05 ];
extern Context* hashtab_02[ HASH_SLOTS_02 ];
extern inline void     hash_Note_Context_02(   Context* context,   Suffix suffix   ) {
    hashtab_02[ suffix._0_to_7.u_16 ] = context;
}

extern inline void     hash_Drop_Context_02(   Context* context   ) {
    hashtab_02[ context->suffix._0_to_7.u_16 ] = NULL;
}

extern inline Context* hash_Find_Context_02(   Suffix suffix   ) {
    return hashtab_02[ suffix._0_to_7.u_16 ];
}
#endif

#ifdef SEEM_TO_HURT_MORE_THAN_HELP
extern Context* hashtab_03[ HASH_SLOTS_03 ];
extern Context* hashtab_04[ HASH_SLOTS_04 ];
extern Context* hashtab_08[ HASH_SLOTS_08 ];
extern Context* hashtab_12[ HASH_SLOTS_12 ];
extern Context* hashtab_16[ HASH_SLOTS_16 ];

extern inline void     hash_Note_Context_03(   Context* context,   Suffix suffix   ) {

    u32 hash32 = suffix._0_to_7.u_32;
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_03;

    context->hashlink = hashtab_03[ hash32 ];
    hashtab_03[ hash32 ] = context;
}

extern inline void     hash_Drop_Context_03(   Context* context   ) {

    Suffix suffix = context->suffix;
    u32 hash32 = suffix._0_to_7.u_32;
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_03;

    {   Context** patchpoint = &hashtab_03[ hash32 ];
        Context*  c;
        for (c = *patchpoint;   c;   patchpoint = &c->hashlink, c = *patchpoint) {
            if (c->suffix._0_to_7.u_32 == suffix._0_to_7.u_32 ){
                *patchpoint = c->hashlink;
                return;  
            }
        }
    }
    assert( 0 && "Attempt to drop Context not in hashtab_03[]" );
}

extern inline Context* hash_Find_Context_03(   Suffix suffix   ) {

    u32 hash32 = suffix._0_to_7.u_32;
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_03;

    {   Context* c;
        for (c = hashtab_03[ hash32 ];   c;   c = c->hashlink) {
            if (c->suffix._0_to_7.u_32 == suffix._0_to_7.u_32){
                return c;
            }
        }
    }
    return NULL;
}



extern inline void     hash_Note_Context_04(   Context* context,   Suffix suffix   ) {

    u32 hash32 = suffix._0_to_7.u_32;
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_04;

    context->hashlink = hashtab_04[ hash32 ];
    hashtab_04[ hash32 ] = context;
}

extern inline void     hash_Drop_Context_04(   Context* context   ) {

    Suffix suffix = context->suffix;

    u32 hash32 = suffix._0_to_7.u_32;
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_04;

    {   Context** patchpoint = &hashtab_04[ hash32 ];
        Context*  c;
        for (c = *patchpoint;   c;   patchpoint = &c->hashlink, c = *patchpoint) {
            if (c->suffix._0_to_7.u_32 == suffix._0_to_7.u_32){
                *patchpoint = c->hashlink;
                return;  
            }
        }
    }
    assert( 0 && "Attempt to drop Context not in hashtab_04[]" );
}

extern inline Context* hash_Find_Context_04(   Suffix suffix   ) {

    u32 hash32 = suffix._0_to_7.u_32;
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_04;

    {   Context* c;
        for (c = hashtab_04[ hash32 ];   c;   c = c->hashlink) {
            if (c->suffix._0_to_7.u_32 == suffix._0_to_7.u_32){
                return c;
            }
        }
    }
    return NULL;
}



extern inline void     hash_Note_Context_05(   Context* context,   Suffix suffix   ) {

    u64 hash64 = suffix._0_to_7.u_64;
    u32 hash32 = hash64 + (hash64 >> 32);
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_05;

    context->hashlink = hashtab_05[ hash32 ];
    hashtab_05[ hash32 ] = context;
}

extern inline void     hash_Drop_Context_05(   Context* context   ) {

    Suffix suffix = context->suffix;

    u64 hash64 = suffix._0_to_7.u_64;
    u32 hash32 = hash64 + (hash64 >> 32);
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_05;

    {   Context** patchpoint = &hashtab_05[ hash32 ];
        Context*  c;
        for (c = *patchpoint;   c;   patchpoint = &c->hashlink, c = *patchpoint) {
            if (c->suffix._0_to_7.u_64 == suffix._0_to_7.u_64){
                *patchpoint = c->hashlink;
                return;  
            }
        }
    }
    assert( 0 && "Attempt to drop Context not in hashtab_5[]" );
}

extern inline Context* hash_Find_Context_05(   Suffix suffix   ) {

    u64 hash64 = suffix._0_to_7.u_64;
    u32 hash32 = hash64 + (hash64 >> 32);
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_05;

    {   Context* c;
        for (c = hashtab_05[ hash32 ];   c;   c = c->hashlink) {
            if (c->suffix._0_to_7.u_64 == suffix._0_to_7.u_64){
                return c;
            }
        }
    }
    return NULL;
}




extern inline void     hash_Note_Context_08(   Context* context,   Suffix suffix   ) {

    u64 hash64 = suffix._0_to_7.u_64;
    u32 hash32 = hash64 + (hash64 >> 32);
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_08;

    context->hashlink = hashtab_08[ hash32 ];
    hashtab_08[ hash32 ] = context;
}

extern inline void     hash_Drop_Context_08(   Context* context   ) {

    Suffix suffix = context->suffix;

    u64 hash64 = suffix._0_to_7.u_64;
    u32 hash32 = hash64 + (hash64 >> 32);
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_08;

    {   Context** patchpoint = &hashtab_08[ hash32 ];
        Context*  c;
        for (c = *patchpoint;   c;   patchpoint = &c->hashlink, c = *patchpoint) {
            if (c->suffix._0_to_7.u_64 == suffix._0_to_7.u_64){
                *patchpoint = c->hashlink;
                return;  
            }
        }
    }
    assert( 0 && "Attempt to drop Context not in hashtab_08[]" );
}

extern inline Context* hash_Find_Context_08(   Suffix suffix   ) {

    u64 hash64 = suffix._0_to_7.u_64;
    u32 hash32 = hash64 + (hash64 >> 32);
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_08;

    {   Context* c;
        for (c = hashtab_08[ hash32 ];   c;   c = c->hashlink) {
            if (c->suffix._0_to_7.u_64 == suffix._0_to_7.u_64){
                return c;
            }
        }
    }
    return NULL;
}




extern inline void     hash_Note_Context_12(   Context* context,   Suffix suffix   ) {

    u64 hash64 = suffix._0_to_7.u_64 + suffix._8_to_F.u_32;
    u32 hash32 = hash64 + (hash64 >> 32);
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_12;

    context->hashlink = hashtab_12[ hash32 ];
    hashtab_12[ hash32 ] = context;
}

extern inline void     hash_Drop_Context_12(   Context* context   ) {

    Suffix suffix = context->suffix;

    u64 hash64 = suffix._0_to_7.u_64 + suffix._8_to_F.u_32;
    u32 hash32 = hash64 + (hash64 >> 32);
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_12;

    {   Context** patchpoint = &hashtab_12[ hash32 ];
        Context*  c;
        for (c = *patchpoint;   c;   patchpoint = &c->hashlink, c = *patchpoint) {
            if (c->suffix._0_to_7.u_64 == suffix._0_to_7.u_64
            &&  c->suffix._8_to_F.u_32 == suffix._8_to_F.u_32
            ){
                *patchpoint = c->hashlink;
                return;  
            }
        }
    }
    assert( 0 && "Attempt to drop Context not in hashtab_12[]" );
}

extern inline Context* hash_Find_Context_12(   Suffix suffix   ) {

    u64 hash64 = suffix._0_to_7.u_64 + suffix._8_to_F.u_32;
    u32 hash32 = hash64 + (hash64 >> 32);
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_12;

    {   Context* c;
        for (c = hashtab_12[ hash32 ];   c;   c = c->hashlink) {
            if (c->suffix._0_to_7.u_64 == suffix._0_to_7.u_64
            &&  c->suffix._8_to_F.u_32 == suffix._8_to_F.u_32
            ){
                return c;
            }
        }
    }
    return NULL;
}




extern inline void     hash_Note_Context_16(   Context* context,   Suffix suffix   ) {

    u64 hash64 = suffix._0_to_7.u_64 + suffix._8_to_F.u_64;
    u32 hash32 = hash64 + (hash64 >> 32);
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_16;

    context->hashlink = hashtab_16[ hash32 ];
    hashtab_16[ hash32 ] = context;
}

extern inline void     hash_Drop_Context_16(   Context* context   ) {

    Suffix suffix = context->suffix;

    u64 hash64 = suffix._0_to_7.u_64 + suffix._8_to_F.u_64;
    u32 hash32 = hash64 + (hash64 >> 32);
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_16;

    {   Context** patchpoint = &hashtab_16[ hash32 ];
        Context*  c;
        for (c = *patchpoint;   c;   patchpoint = &c->hashlink, c = *patchpoint) {
            if (c->suffix._0_to_7.u_64 == suffix._0_to_7.u_64
            &&  c->suffix._8_to_F.u_64 == suffix._8_to_F.u_64
            ){
                *patchpoint = c->hashlink;
                return;  
            }
        }
    }
    assert( 0 && "Attempt to drop Context not in hashtab_16[]" );
}

extern inline Context* hash_Find_Context_16(   Suffix suffix   ) {

    u64 hash64 = suffix._0_to_7.u_64 + suffix._8_to_F.u_64;
    u32 hash32 = hash64 + (hash64 >> 32);
    hash32     = hash32 + (hash32 >> 16);
    hash32    &= HASH_MASK_16;

    {   Context* c;
        for (c = hashtab_16[ hash32 ];   c;   c = c->hashlink) {
            if (c->suffix._0_to_7.u_64 == suffix._0_to_7.u_64
            &&  c->suffix._8_to_F.u_64 == suffix._8_to_F.u_64
            ){
                return c;
            }
        }
    }
    return NULL;
}

#endif /* __GNUC__ */


#endif /* HASH_H */
