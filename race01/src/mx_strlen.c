#include "part_of_mx.h"

int mx_strlen(const char *s) {
  int len = 0;
  char i = s[0];
  while (i != '\0') {
    len++;
    i = s[len];
  }
  return len;
}
