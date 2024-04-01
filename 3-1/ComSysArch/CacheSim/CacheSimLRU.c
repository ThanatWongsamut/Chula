#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define WAYLEN 2                                       // Bit Length of Way Size
#define BLOCKLEN 2                                     // Bit Length of Block Size
#define INDEXLEN ((int)(10 + 0) - (BLOCKLEN + WAYLEN)) // Bit Length of Index (1,4,8,32,512,1024 KB -> 10,12,13,15,19,20)

typedef unsigned char Byte;
typedef unsigned char bool;
typedef struct Cache
{
  bool valid;
  int lru;
  unsigned long tag;
};

long MISS;
long HIT;
struct Cache cache[1 << WAYLEN][1 << INDEXLEN];
int cur[1 << INDEXLEN];
int turn = 0;

int init()
{
  MISS = 0;
  HIT = 0;
  int i, j;
  for (i = 0; i < 1 << INDEXLEN; i++)
  {
    cur[i] = 0;
    for (j = 0; j < 1 << WAYLEN; j++)
    {
      cache[j][i].valid = 0;
      cache[j][i].lru = -1;
      cache[j][i].tag = 0;
    }
  }
}
int calAddr(unsigned long addr, unsigned long *tag, unsigned long *idx,
            unsigned long *offset)
{
  unsigned long tmp;
  int i;
  *tag = addr >> (INDEXLEN + BLOCKLEN);
  tmp = 0;
  for (i = 0; i < INDEXLEN; i++)
  {
    tmp <<= 1;
    tmp |= 0x01;
  }
  *idx = addr >> BLOCKLEN & tmp;
  tmp = 0;
  for (i = 0; i < BLOCKLEN; i++)
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

  bool isHit = 0;

  for (int i = 0; i < (1 << WAYLEN); i++)
  {
    if (cache[i][idx].valid && cache[i][idx].tag == tag)
    {
      cache[i][idx].lru = turn;
      isHit = 1;
    }
  }

  if (isHit)
  {
    HIT++;
  }
  else
  {
    MISS++;

    int j = 0;
    for (int i = 0; i < (1 << WAYLEN); i++)
    {
      if (cache[i][idx].lru < cache[j][idx].lru)
        j = i;
    }

    cache[j][idx].valid = 1;
    cache[j][idx].tag = tag;
    cache[j][idx].lru = turn;
  }

  turn++;
}
int main(int argc, char *argv[])
{
  FILE *input;
  char buff[1025];
  unsigned long myaddr;
  if (argc < 2)
  {
    fprintf(stderr, "Please specify address file\n");
    exit(-1);
  }
  input = fopen(argv[1], "r");
  // read file
  while (fgets(&buff[0], 1024, input))
  {
    sscanf(buff, "0x%x", &myaddr);
    access(myaddr);
  }
  printf("HIT: %7d\n", HIT);
  printf("MISS: %7d\n", MISS);
  // printf("MISS RATIO: %f\n", (float)MISS / (float)(HIT + MISS));
}