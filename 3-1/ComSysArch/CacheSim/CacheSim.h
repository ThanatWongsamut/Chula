/**
 * CacheSim.h
 * This program is designed for class exercise only.
 * It is provided as is. There is no warranty or support of any kind.
 *
 * Krerk Piromsopa, Ph.D.
 * Department of Computer Engineering
 * Chulalongkorn University
 * Bangkok, Thailand.
 **/
#ifndef CACHESIM_H_INCLUDED
#define CACHESIM_H_INCLUDED

/* Please adjust parameters here */
#define CACHE_SIZE 1024 * 32
#define BLOCK_SIZE 32
#define INDEX_SIZE (CACHE_SIZE / BLOCK_SIZE)
// #define TAGLEN 22
#define INDEXLEN (int)(log2(INDEX_SIZE))
#define OFFSETLEN (int)(log2(BLOCK_SIZE))
typedef unsigned char Byte;
typedef unsigned char bool;
typedef struct Cache
{
    bool valid;
    bool dirty;
    unsigned long tag;
    Byte data[BLOCK_SIZE];
};

#endif // CACHESIM_H_INCLUDED
