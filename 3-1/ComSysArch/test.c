#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main()
{
  size_t alignment = 38; // Adjust the desired alignment here

  void *ptr = NULL;
  int *intPtr = NULL;

  // Allocate memory with the desired alignment
  if (posix_memalign(&ptr, alignment, sizeof(int)) != 0)
  {
    printf("Memory allocation failed.\n");
    return 1;
  }

  intPtr = (int *)ptr;

  // Check if the allocated memory is properly aligned
  if (((uintptr_t)intPtr % alignment) == 0)
  {
    printf("Memory is properly aligned to %zu bytes.\n", alignment);
  }
  else
  {
    printf("Memory is not properly aligned to %zu bytes.\n", alignment);
  }

  free(ptr);

  return 0;
}
