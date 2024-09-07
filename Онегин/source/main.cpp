#include <stdio.h>
#include "sort.h"
#include "array_string.h"
#include "comparison_elements.h"

int main()
{
    MyFile onegin = {};
    ArrayPtr array_ptr = {};

    ErrorOnegin error_onegin = write_on_file("onegin.txt", &onegin);
    if (error_onegin != ERROR_NO)
        return error_onegin;

    error_onegin = create_array_ptr(&onegin, &array_ptr);
    if (error_onegin != ERROR_NO)
        return error_onegin;

    quick_sort((void*)array_ptr.ptr, array_ptr.size, sizeof(char*), MyStrcpm);

    for (int i = 0; i < array_ptr.size; i++)
        printf("%s\n", *(array_ptr.ptr + i));
}


