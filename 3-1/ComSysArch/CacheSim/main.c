#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "CacheSim.h"

#define CACHE_SIZE 1024 * 16
#define BLOCK_SIZE 32
#define INDEX_SIZE (CACHE_SIZE / BLOCK_SIZE)
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

long MISS;
long HIT;
struct Cache cache[INDEX_SIZE];
int init()
{
  MISS = 0;
  HIT = 0;
  int i;
  for (i = 0; i < INDEX_SIZE; i++)
  {
    cache[i].valid = 0;
    cache[i].tag = 0;
    cache[i].dirty = 0;
  }
}
int calAddr(unsigned long addr, unsigned long *tag, unsigned long *idx, unsigned long *offset)
{
  unsigned long tmp;
  int i;
  *tag = addr >> (OFFSETLEN + INDEXLEN);
  tmp = 0;
  for (i = 0; i < INDEXLEN; i++)
  {
    tmp <<= 1;
    tmp |= 0x01;
  }
  *idx = addr >> OFFSETLEN & tmp;
  tmp = 0;
  for (i = 0; i < OFFSETLEN; i++)
  {
    tmp <<= 1;
    tmp |= 0x01;
  }
  *offset = addr & tmp;
}
int access(unsigned long addr)
{
  unsigned long offset;
  unsigned long tag;
  unsigned long idx;
  int i;
  int valid = 0;
  calAddr(addr, &tag, &idx, &offset);
  if (cache[idx].tag == tag && cache[idx].valid)
  {
    HIT++;
  }
  else
  {
    MISS++;
    cache[idx].valid = 1;
    cache[idx].tag = tag;
  }
}

int main(int argc, char *argv[])
{
  printf("CacheSim v.2015\n");
  printf("This program is designed for class exercise only.\n");
  printf("By Krerk Piromsopa, Ph.D.\n");

  FILE *input;
  char buff[1025];
  unsigned long myaddr;

  if (argc < 2)
  {
    fprintf(stderr, "Usage:\n\t%s address_file\n", argv[0]);
    exit(-1);
  }

  int CACHE_SIZES[] = {4 * 1024, 8 * 1024, 16 * 1024, 32 * 1024};
  int BLOCK_SIZES[] = {4, 8, 16, 32};

  // Loop over different CACHE_SIZE values
  for (int i = 0; i < 4; i++)
  {
    CACHE_SIZE = CACHE_SIZES[i];
    INDEX_SIZE = CACHE_SIZE / BLOCK_SIZE;

    // Loop over different BLOCK_SIZE values
    for (int j = 0; j < 4; j++)
    {
      int BLOCK_SIZE = BLOCK_SIZES[j];
      int INDEXLEN = (int)(log2(INDEX_SIZE));
      int OFFSETLEN = (int)(log2(BLOCK_SIZE));

      // Initialize cache with current CACHE_SIZE and BLOCK_SIZE
      init();

      input = fopen(argv[1], "r");

      // Read file
      while (fgets(&buff[0], 1024, input))
      {
        sscanf(buff, "0x%x", &myaddr);
        access(myaddr);
      }

      fclose(input);

      // Print results for current CACHE_SIZE and BLOCK_SIZE
      printf("CACHE_SIZE: %d, BLOCK_SIZE: %d, HIT:%7ld MISS: %7ld\n", CACHE_SIZE, BLOCK_SIZE, HIT, MISS);
      printf("MISS RATIO: %f\n", (float)MISS / (float)(HIT + MISS));
    }
  }

  return 0;
}
