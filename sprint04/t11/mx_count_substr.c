char *mx_strstr(const char *, const char *);
char *mx_strchr(const char *, int);
int mx_strlen(const char *);
int mx_strncmp(const char*, const char*, int);

int mx_count_substr(const char *str, const char *sub){
    int counter = 0;
    while ( (str=mx_strstr(str,sub)) != 0 ) {
            str += mx_strlen(sub);
            counter++;
    }
    return counter;
}
