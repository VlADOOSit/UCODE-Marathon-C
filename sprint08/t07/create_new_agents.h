#ifndef CREATE_NEW_AGENT_H
#define CREATE_NEW_AGENT_H

#include <stdlib.h>
#include "agent.h"

typedef struct s_agent t_agent;

char* mx_strcpy(char *, const char *);
int mx_strlen(const char * str);
char *mx_strnew(const int size);
char *mx_strdup(const char * str);
char* mx_strcpy(char * dst, const char * src);
t_agent **mx_create_new_agents(char **name, int *power, int *strength, int count);
t_agent *mx_create_agent(char *name, int power, int strength);

#endif
