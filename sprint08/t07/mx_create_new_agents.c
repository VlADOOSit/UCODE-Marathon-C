#include "create_new_agents.h"

t_agent **mx_create_new_agents(char **name, int *power, int *strength, int count) {
    if (name == NULL || power == NULL || strength == NULL || count < 0) {
        return NULL;
    }
    t_agent **more_new = malloc(sizeof(t_agent*) * count + 1);
    for (int i = 0; i < count; i++) {
        more_new[i] = mx_create_agent(name[i], power[i], strength[i]);
    }
    more_new[count]] = NULL;
    return more_new;
}
