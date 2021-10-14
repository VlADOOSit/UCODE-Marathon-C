#include <stdbool.h>

void mx_sort_arr_int(int *arr, int size) 
{
    bool flag;
    for (int i = 0; i < size; i++) 
    {
        flag = true;
        for (int j = 1; j < size - i; j++)
            if (arr[j] < arr[j - 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                flag = false;
            }
        if (flag)
            return;
    }
}
