#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
  printf("Enter binary: ");
  char *n = (char *)malloc(32 * sizeof(char));
  scanf("%s", n);
  int size = strlen(n);
  int b = 1, c = 1;
  unsigned int d = 0;
  for (int i = size - 1; i >= 0; i--)
  {
    if (n[i] - '0' > 1)  // for numbers except binary
    {
      printf("Invalid Input");
      c = 0;
      break;
    }
    d += (n[i] - '0') * b; // taking each element from the right and multiplying it with b
    b *= 2;                // each iteration multiply b with 2
  }
  if (c == 1)
  {
    printf("Decimal equivalent: %d\n", d);
    printf("The number of multiplications: %d\n", (size * (size - 1) / 2) + 1);
    printf("The number of addition: %d\n", size);
  }
  return 0;
}