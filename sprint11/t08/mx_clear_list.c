#include "list.h"

void mx_clear_list(t_list **list) {
    if (*list == NULL || list == NULL) {
        *list = mx_create_node(data);
        return;
    }
    t_list *curr;
    while (*list) {
        curr = *list;
        if ((*list)->next) {
            *list = (*list)->next;
            free(curr);
        } else {
            free(curr);
            *list = NULL;
            return;
        }
    }
}
