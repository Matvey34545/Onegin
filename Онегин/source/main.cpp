#include <stdio.h>
#include "sort.h"
#include "array_string.h"
#include "comparison_elements.h"
#include "argv_command_line.h"

int main(int argc, char *argv[])
{
    MyFile onegin = {};
    ArrayPtr array_ptr = {};
    Flags flags = {};

    ErrorOnegin error_onegin  =read_command_line(argv, argc, &flags);
    if (error_onegin != ERROR_NO)
        return error_onegin;

    error_onegin = read_on_file(flags.source_file, &onegin);
    if (error_onegin != ERROR_NO)
        return error_onegin;

    error_onegin = create_array_ptr(&onegin, &array_ptr);
    if (error_onegin != ERROR_NO)
        return error_onegin;
    fprintf( stderr, "success\n");
    quick_sort((void*)array_ptr.ptr, array_ptr.size, sizeof(String), MyStrcpm);

    error_onegin = write_on_file(flags.format_file, &array_ptr);
    if (error_onegin != ERROR_NO)
        return error_onegin;
    printf("end: %d\n", error_onegin);
}


