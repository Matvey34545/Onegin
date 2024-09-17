#include "argv_command_line.h"
#include "comparison_elements.h"
#include "sort.h"

#include <string.h>
#include <stdio.h>

ErrorOnegin read_command_line(char **argv, int argc, Flags *flags)
{
    flags->func_comparison = MyStrcpm;
    flags->func_sort = qsort;
    argv++;
    while (argc > 1)
    {
        if (strcmp(*argv, "-back") == 0)
        {
            flags->func_comparison = back_my_strcpm;
            argc--;
            argv++;
            continue;
        }
        if (strcmp(*argv, "-myqsort") == 0)
        {
            flags->func_sort = quick_sort;
            argc--;
            argv++;
            continue;
        }
        if (strcmp(*argv, "-o") == 0)
        {
            if (argc < 3)
                return ERROR_FLAG;

            flags->format_file = *(argv + 1);
            argc -= 2;
            argv += 2;
            continue;
        }
        flags->source_file = *argv;
        argc--;
        argv++;
    }

    return ERROR_NO;
}





