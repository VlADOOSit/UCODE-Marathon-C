#include "part_of_mx.h"

char *mx_strtrim(const char *str) {
  if (str != NULL) {
    int size = 0, cntr_l = 0, cntr_r = 0;

    while (*str) {
      size++;
      str++;
    }
    str -= size;

    while (mx_isspace(*str) && *str) {
      str++;
      cntr_l++;
    }
    str -= cntr_l;
      
    for (int i = size - 1; i >= cntr_l; i--) {
      if(!mx_isspace(str[i]))
        break;
      cntr_r++;
    }
      
    char *array = mx_strnew(size - cntr_l - cntr_r);
      
    for (int i = cntr_l, j = 0; i <= size - 1 - cntr_r; i++, j++) 
      array[j] = str[i];
          
    return array;
  } 
  return NULL;
}
