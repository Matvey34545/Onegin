#include "array_string.h"

#include <stdlib.h>
#include <stdio.h>

ErrorOnegin write_on_file(const char* filename, MyFile *file)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return ERROR_NO_FILE;

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp) + 1;
    rewind(fp);

    file->ptr_str = (char*)calloc(file->size, sizeof(char));
    if (file->ptr_str == NULL)
        return ERROR_ALLOCATION;

    fread(file->ptr_str, sizeof(char), file->size - 1, fp);
    fclose(fp);
    return ERROR_NO;
}

ErrorOnegin create_array_ptr(MyFile *file, ArrayPtr *array_ptr)
{
    char *ptr = file->ptr_str;
    int count = 1;
    for (int i = 0; i < file->size; i++)
    {
        if (*(ptr + i) == '\n')
            count++;
    }
    array_ptr->size = count;
    array_ptr->ptr = (char**)calloc(array_ptr->size, sizeof(char*));
    if (array_ptr->ptr == NULL)
        return ERROR_ALLOCATION;

    char **ptr_str = array_ptr->ptr;
    *(ptr_str) = file->ptr_str;
    int j = 1;
    for (int i = 0; i < file->size && j < count; i++)
    {
        if (*(ptr + i) == '\n')
        {
            *(ptr + i) = '\0';
            *(ptr_str +j) = ptr + i + 1;
            j++;
        }
    }
    return ERROR_NO;
}




