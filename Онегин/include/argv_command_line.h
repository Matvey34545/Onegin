#ifndef ARGV_COMMAND_LINE
#define ARGV_COMMAND_LINE

#include "array_string.h"

#include <stdlib.h>

struct Flags
{
    bool is_back_sort;
    bool is_mysort;
    bool is_flag_o;
    bool is_source_file;
    bool is_format_file;
    const char *source_file;
    const char *format_file;
};

ErrorOnegin read_command_line(char **argv, int argc, Flags *flags);

#endif
