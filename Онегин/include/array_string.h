#ifndef ARRAY_STRING
#define ARRAY_STRING

#include <stdlib.h>

enum ErrorOnegin
{
    ERROR_NO         = 0,
    ERROR_NO_FILE    = 1,
    ERROR_ALLOCATION = 2,
    ERROR_FLAG       = 3,
    ERROR_WRITE      = 4
};

struct MyFile
{
    char *ptr_str;
    long int size;
};

struct String
{
    char* str;
    int len;
};

struct ArrayPtr
{
    String *ptr;
    int size;
};

ErrorOnegin read_on_file(const char* filename, MyFile *file);
ErrorOnegin create_array_ptr(MyFile *file, ArrayPtr *array_ptr);
ErrorOnegin write_on_file(const char* filename, ArrayPtr *array_ptr);

#endif
