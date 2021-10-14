#ifndef ONLY_SMITH_H
#define ONLY_SMITH_H

#include <stdlib.h>
#include "agent.h"
#include <stdio.h>
#include <string.h>

typedef struct s_agent t_agent;

t_agent**mx_only_smiths(t_agent**agents, int strength);

int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char * str);
char *mx_strnew(const int size);
char *mx_strdup(const char * str);
char* mx_strcpy(char * dst, const char * src);
t_agent *mx_create_agent(char *name, int power, int strength);
t_agent **mx_only_smiths(t_agent **agents, int strength);
void mx_exterminate_agents(t_agent ***agents);

#endif