#include "sort.h"
#include "array_string.h"
#include "comparison_elements.h"
#include "argv_command_line.h"

#include <stdlib.h>

int main(int argc, const char *argv[])
{
    MyFile onegin = {};
    ArrayPtr array_ptr = {};
    Flags flags = {};

    ErrorOnegin error_onegin = read_command_line(argv, argc, &flags);
    if (error_onegin != ERROR_NO)
        return error_onegin;

    error_onegin = read_on_file(flags.source_file, &onegin);
    if (error_onegin != ERROR_NO)
        return error_onegin;

    error_onegin = create_array_ptr(&onegin, &array_ptr);
    if (error_onegin != ERROR_NO)
        return error_onegin;

    if (flags.is_mysort)
    {
        if (flags.is_back_sort)
            quick_sort((void*)array_ptr.ptr, array_ptr.size, sizeof(String), back_my_strcpm);
        else
            quick_sort((void*)array_ptr.ptr, array_ptr.size, sizeof(String), MyStrcpm);
    }
    else
    {
        if (flags.is_back_sort)
            qsort((void*)array_ptr.ptr, array_ptr.size, sizeof(String), back_my_strcpm);
        else
            qsort((void*)array_ptr.ptr, array_ptr.size, sizeof(String), MyStrcpm);
    }

    error_onegin = write_on_file(flags.format_file, &array_ptr, &onegin);
    if (error_onegin != ERROR_NO)
        return error_onegin;

    destroy_arrays(&array_ptr, &onegin);
}
