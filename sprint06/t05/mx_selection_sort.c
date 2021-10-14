int mx_strcmp(const char *, const char *);
int mx_strlen(const char *);

int mx_selection_sort(char **arr, int size)
{  
    int counter = 0;
    for (int i = 0; i < size-1; i++)
    {
        int min = i;
        for (int j = i+1; j < size; j++) {
            if (mx_strlen(arr[j]) < mx_strlen(arr[min])) {
                min = j;
            }
            if (mx_strlen(arr[j]) == mx_strlen(arr[min])) {
                if(mx_strcmp(arr[j], arr[min]) < 0) {
                    min = j;
                }
            }
        }
        if(i != min) {
            char* temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
            counter++;
        }
    }
    return counter;
}
