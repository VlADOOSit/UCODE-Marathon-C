#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct s_list {
    void *data;
    structs_list *next;
} t_list;

t_list *mx_create_node(void *data);

#endif
