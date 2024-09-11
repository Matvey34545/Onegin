#include "array_string.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

ErrorOnegin read_on_file(const char* filename, MyFile *file)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fclose( fp);
        return ERROR_NO_FILE;
    }
    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp) + 1;
    rewind(fp);

    file->ptr_str = (char*)calloc(file->size, sizeof(char));
    if (file->ptr_str == NULL)
    {
        fclose( fp);
        return ERROR_ALLOCATION;
    }

    fread(file->ptr_str, sizeof(char), file->size - 1, fp);
    fclose(fp);
    return ERROR_NO;
}

ErrorOnegin create_array_ptr(MyFile *file, ArrayPtr *array_ptr)
{
    char *ptr = file->ptr_str;
    int count = ( file->size ) ? 1 : 0;
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

ErrorOnegin write_on_file(const char* filename, ArrayPtr *array_ptr)
{
    FILE *fn = fopen( filename, "a");
    assert (fn);
    fprintf( stderr, "opened\n");
    if ( !fn )
    {
        printf( "error\n");
        return ERROR_NO_FILE;
    }
    fprintf( stderr, "ready to print\n");
    fprintf( stderr, "fprintf: %d\n", fprintf( fn, "new word"));
    fprintf( stderr, "printed\n");
    fclose( fn);
    return ERROR_NO;
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
        return ERROR_NO_FILE;

    for ( int i = 0; i < array_ptr->size; i++)
        printf("%s\n", (array_ptr->ptr + i)->str);

    for ( int i = 0; i < array_ptr->size; i++)
    {
        fprintf( stderr, "try str: %s\n", array_ptr->ptr[i].str);
        int error = 0; //fputs(array_ptr->ptr[i].str, fp);
        fprintf( fp, "test str\n");
        fprintf( stderr, "written str: %s\n", array_ptr->ptr[i].str);
        if (error == EOF)
            return ERROR_WRITE;
    }
    fclose(fp);
    return ERROR_NO;
}




