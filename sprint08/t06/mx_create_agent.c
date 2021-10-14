#include "create_agent.h"

t_agent *mx_create_agent(char *name, int power, int strength) {
    if (name == NULL || power < 0 || strength < 0) {
        return NULL;
    }
    t_agent *new = malloc(sizeof(t_agent*));
    new->name = mx_strdup(name);
    new->power = power;
    new->strength = strength;
    return new;
}
