#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include "comparison_elements.h"
#include "array_string.h"

bool MyStrcpm(const void *s1, const void *s2, size_t size_element)
{
    char temp1 = 'a';
    char temp2 = 'a';
    char *ptr_s1 = ((String*)s1)->str;
    char *ptr_s2 = ((String*)s2)->str;

    while( *ptr_s1 != '\0' && *ptr_s2 != '\0' )
    {
        while(!isalpha(*ptr_s1) && *ptr_s1 != '\0')
            ptr_s1++;

        while(!isalpha(*ptr_s2) && *ptr_s2 != '\0')
            ptr_s2++;

        if (*ptr_s1 != '\0' && *ptr_s2 != '\0')
        {
            temp1 = tolower(*ptr_s1);
            temp2 = tolower(*ptr_s2);

            if (temp1 > temp2)
                return true;

            if (temp2 > temp1)
                return false;

            ptr_s1++;
            ptr_s2++;
        }
    }
    if (*ptr_s1 == '\0')
    {
        if (*ptr_s2 == '\0')
            return true;

        return false;
    }
    if (*ptr_s2 == '\0')
        return true;
}

bool comparison_unsigned(const void* elem1, const void* elem2, size_t size_element)
{
    bool result = true;
    for (int i = size_element - 1; i > -1; i--)
    {
        if ( *((char*)elem1 + i) > *((char*)elem2 + i) )
        {
            result = true;
            break;
        }
        if ( *((char*)elem1 + i) < *((char*)elem2 + i) )
        {
            result = false;
            break;
        }
    }
    return result;
}

