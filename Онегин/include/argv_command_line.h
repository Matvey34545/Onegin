#ifndef ARGV_COMMAND_LINE
#define ARGV_COMMAND_LINE

#include "array_string.h"

#include <stdlib.h>

struct Flags
{
    int (*func_comparison)(const void*, const void*);
    void (*func_sort)(void*, size_t, size_t, int (*func_comparison)(const void*, const void*));
    const char *source_file;
    const char *format_file;
};

ErrorOnegin read_command_line(char **argv, int argc, Flags *flags);

#endif
