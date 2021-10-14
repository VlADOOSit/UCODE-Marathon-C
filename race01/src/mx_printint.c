#include "part_of_mx.h"

void mx_printint(int n) {
  char array[55];
  long bufnum = n;
  int i = 0;

  if (bufnum == 0)
    mx_printchar(n + '0');
  if (bufnum < 0) {
    bufnum *= -1;
    mx_printchar('-');
  }

  while (bufnum != 0) {
    array[i++] = (bufnum % 10) + '0';
    bufnum /= 10;
  }

  for (int j = i - 1; j >= 0; j--)
    mx_printchar(array[j]);
}
