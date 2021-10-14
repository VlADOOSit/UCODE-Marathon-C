#include "part_of_mx.h"

char *mx_itoa(long long number) {
    char *n_str = NULL;
  if (number == 0) {
    n_str = mx_strnew(1);
    n_str[0] = '0';
    return n_str;
  }

  int len = 0;
  long long bufnum = number;
  if (bufnum < 0) {
    len++;
    bufnum *= -1;
  }
  while (bufnum != 0) {
    bufnum /= 10;
    len++;
  }

  n_str = mx_strnew(len);
    
  if (number < 0) {
    n_str[0] = '-';
    number *= -1;
  }
  n_str[len--] = '\0';
  while ((number != 0 && len >= 0) && n_str[len] != '-') {
    n_str[len--] = (number % 10) + '0';
    number /= 10;
  }
  return n_str;
}
