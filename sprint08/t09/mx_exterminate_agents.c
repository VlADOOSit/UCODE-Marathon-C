#include "only_smiths.h"

void mx_exterminate_agents(t_agent ***agents) {
    int i = 0;
    t_agent **deez = *agents;

    while (deez[i]) {
        free(deez[i]->name);
        free(deez[i]);
        i++;
    }
    free(deez);
    agents = (t_agent ***)0;
    return;
}
