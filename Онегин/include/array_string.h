#ifndef ARRAY_STRING
#define ARRAY_STRING

#include <stdlib.h>

enum ErrorOnegin
{
    ERROR_NO         = 0,
    ERROR_NO_FILE    = 1,
    ERROR_ALLOCATION = 2
};

struct MyFile
{
    char *ptr_str;
    long int size;
};

struct ArrayPtr
{
    char **ptr;
    int size;
};

ErrorOnegin write_on_file(const char* filename, MyFile *file);
ErrorOnegin create_array_ptr(MyFile *file, ArrayPtr *array_ptr);

#endif
