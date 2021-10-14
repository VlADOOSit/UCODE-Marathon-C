#include "header.h"



bool c_name(t_agent* ag1, t_agent* ag2){
    return mx_strcmp(ag1->name, ag2->name) < 0 ? true : false;
}

bool c_power(t_agent* ag1, t_agent* ag2){
    return ag1->power < ag2->power ? true : false;
}

bool c_strength(t_agent* ag1, t_agent* ag2){
    return ag1->strength < ag2->strength ? true : false;
}

void sort(t_agent **arr, bool (*compare)(t_agent*, t_agent*), int size){
    bool was_swap = true;
    t_agent* temp = malloc(sizeof(t_agent*));
    while(was_swap){
        was_swap = false;
        for(int i = 1; i < size; i++){
            if(compare(arr[i], arr[i - 1])){
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                was_swap = true;
            }
        }
    }
}

int main(int argc, char *argv[]){
    if(argc != 3 || mx_strlen(argv[1]) > 2){
        mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
        exit(0);
    }
    char *str = mx_file_to_str(argv[2]);
    int counter = mx_count_substr(str, "agent");
    int k = 0;
    t_agent **arr = (t_agent**)malloc(counter * sizeof(t_agent*));
    for(int i = 0; i < counter; i++){
        arr[i] = (t_agent*)malloc(sizeof(t_agent) * counter);
    }
    
    char str_cheacked1[] = "agent {\n\tname: ";
    char str_cheacked2[] = "\tpower: ";
    char str_cheacked3[] = "\tstrength: ";
    char str_cheacked4[] = "}\n";
    char *temp;
    for(int i = 0; i < counter; i++){
        for(int j = 0; j < mx_strlen(str_cheacked1); j++){
            if(*str != str_cheacked1[j]){
                mx_printerr("error\n");
                exit(0);
            }
            str++;
        }
        temp = malloc(60);
        while(*str != '\n'){
            temp[k] = *str;
            str+=1; k+=1;
        }
        arr[i]->name = temp;
        free(temp);
        temp = malloc(60);
        arr[i]->name[k] = '\0';
        str++;
        for(int j = 0; j < mx_strlen(str_cheacked2); j++){
            if(*str != str_cheacked2[j]){
                mx_printerr("error\n");
                exit(0);
            }
            str+=1;
        }

        arr[i]->power = mx_atoi(str);

        int n = arr[i]->power;
        while (n > 0) {
            n /= 10;
            str+=1;
        }
        str++;
        for(int j = 0; j < mx_strlen(str_cheacked3); j++){
            if(*str != str_cheacked3[j]){
                mx_printerr("error\n");
                exit(0);
            }
            str+=1;
        }

        arr[i]->strength = mx_atoi(str);

        n = arr[i]->strength;
        while (n > 0) {
            n /= 10;
            str+=1;
        }
        str++;
        for(int j = 0; j < mx_strlen(str_cheacked4); j++){
            if(*str != str_cheacked4[j]){
                mx_printerr("error\n");
                exit(0);
            }
            str+=1;
        }
        k = 0;
    }

    
    switch(argv[1][1]){
        case 'p':
            sort(arr, c_power, counter);
            break;
        case 's':
            sort(arr, c_strength, counter);
            break;
        case 'n':
            sort(arr, c_name, counter);
            break;
        default:
            mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
            exit(0);
    }


    for (int i = 0; i < counter; i++)
    {
        mx_printstr("agent: ");
        mx_printstr(arr[i]->name);
        mx_printstr(", strength: ");
        mx_printint(arr[i]->strength);
        mx_printstr(", power: ");
        mx_printint(arr[i]->power);
        mx_printchar('\n');
    }


    return 0;
}
