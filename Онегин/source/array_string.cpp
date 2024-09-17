#include "array_string.h"

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#define NDEBUG

ErrorOnegin read_on_file(const char* filename, MyFile *file)
{
    assert(file != NULL);
    struct stat st = {};
    stat(filename, &st);
    file->size = st.st_size + 1;

    file->ptr_str = (char*)calloc(file->size, sizeof(char));
    if (file->ptr_str == NULL)
        return ERROR_ALLOCATION;

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
        return ERROR_NO_FILE;

    size_t ret_fread = fread(file->ptr_str, sizeof(char), file->size - 1, fp);

    fclose(fp);

    return ERROR_NO;
}

ErrorOnegin create_array_ptr(MyFile *file, ArrayPtr *array_ptr)
{
    assert(file != NULL);
    assert(array_ptr != NULL);

    char *ptr = file->ptr_str;

    int count = 1;
    for (int i = 0; i < file->size; i++)
    {
        if (*(ptr + i) == '\n')
            count++;
    }
    array_ptr->size = count;
    array_ptr->ptr = (String*)calloc(array_ptr->size, sizeof(String));
    if (array_ptr->ptr == NULL)
        return ERROR_ALLOCATION;

    String *begin_array_ptr = array_ptr->ptr;
    begin_array_ptr->str = file->ptr_str;
    int number_str = 0;
    int element_str = 0;

    for (int i = 0; i < file->size; i++)
    {
        element_str++;
        if (*(file->ptr_str + i) == '\n' || *(file->ptr_str + i) == '\0')
        {
            if (*(file->ptr_str + i) == '\n')
            {
                (begin_array_ptr + number_str + 1)->str = file->ptr_str + i + 1;
                *(file->ptr_str + i) = '\0';
            }
            (begin_array_ptr + number_str)->len = element_str;
            element_str = 0;
            number_str++;
        }
    }
    return ERROR_NO;
}

ErrorOnegin write_on_file(const char* filename, const ArrayPtr *array_ptr, const MyFile *file)
{
    assert(array_ptr != NULL);
    assert(file != NULL);

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
        fp = fopen("format_onegin.txt", "wb");

    char* buffer = (char*)calloc(file->size, sizeof(char));
    if (buffer == NULL)
        return ERROR_ALLOCATION;

    char* temp = buffer;
    for (int i = 0; i < array_ptr->size; i++)
    {
        strncpy(temp, (array_ptr->ptr + i)->str, (array_ptr->ptr + i)->len);
        if (i != array_ptr->size - 1)
            *(temp + (array_ptr->ptr + i)->len - 1) = '\n';
        temp += (array_ptr->ptr + i)->len;
    }

    int error = fputs(buffer, fp);
    free(buffer);
    if (error == EOF)
        return ERROR_WRITE;
    fclose(fp);
    return ERROR_NO;
}

void destroy_arrays(ArrayPtr *array_ptr, MyFile *file)
{
    free(file->ptr_str);
    free(array_ptr->ptr);
}




