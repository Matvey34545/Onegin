#include "argv_command_line.h"

#include <string.h>
#include <stdio.h>

ErrorOnegin read_command_line(char **argv, int argc, Flags *flags)
{
    argv++;
    while (argc > 1)
    {
        if (strcmp(*argv, "myqsort") == 0)
        {
            flags->is_mysort = true;
            argc--;
            argv++;
            continue;
        }
        if (strcmp(*argv, "o") == 0)
        {
            if (argc < 3)
                return ERROR_FLAG;

            flags->is_flag_o = true;
            flags->is_format_file = true;
            flags->format_file = *(argv + 1);
            argc -= 2;
            argv += 2;
            continue;
        }
        flags->is_source_file = true;
        flags->source_file = *argv;
        argc--;
        argv++;
    }
    return ERROR_NO;
}





