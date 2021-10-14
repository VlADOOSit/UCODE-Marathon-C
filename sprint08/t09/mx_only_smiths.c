#include "only_smiths.h"

t_agent **mx_only_smiths(t_agent **agents, int strength) {
    if(agents == NULL || strength <= 0)
        return NULL;
    int counter = 0;

    for(int i = 0; agents[i] != NULL; i++) {
        if(mx_strcmp(agents[i]->name, "Smith") == 0 && agents[i]->strength < strength) {
            counter++;
        }
    }
    t_agent **new_agents = malloc(sizeof(t_agent *) * counter + 1);

    counter = 0;
    for(int i = 0; agents[i] != NULL; i++)
        if(mx_strcmp(agents[i]->name, "Smith") == 0 && agents[i]->strength < strength) {
            new_agents[counter] = mx_create_agent(agents[i]->name, agents[i]->power, agents[i]->strength);
            counter++; 
        }
    new_agents[counter] = NULL;
    mx_exterminate_agents(&agents);
    return new_agents;
}
