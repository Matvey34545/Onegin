#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include "comparison_elements.h"
#include "array_string.h"

int MyStrcpm(const void *s1, const void *s2)
{
    char temp1 = '\0';
    char temp2 = '\0';
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
                return 1;

            if (temp2 > temp1)
                return -1;

            ptr_s1++;
            ptr_s2++;
        }
    }
    if (*ptr_s1 == '\0')
    {
        if (*ptr_s2 == '\0')
            return 0;

        return -1;
    }
    if (*ptr_s2 == '\0')
        return 1;
}

int back_my_strcpm(const void *s1, const void *s2)
{
    char temp1 = 'a';
    char temp2 = 'a';

    String *ptr_s1 = (String*)s1;
    String *ptr_s2 = (String*)s2;
    char *ptr_s1_end = ptr_s1->str + ptr_s1->len - 2;
    char *ptr_s2_end = ptr_s2->str + ptr_s2->len - 2;

    int count2 = 0;
    int count1 = 0;

    while(count1 < ptr_s1->len - 1 && count2 < ptr_s2->len - 1)
    {
        while(!isalpha(*(ptr_s1_end - count1)) && count1 < ptr_s1->len - 1)
            count1++;

        while(!isalpha(*(ptr_s2_end - count2)) && count2 < ptr_s2->len - 1)
            count2++;

        if (count1 < ptr_s1->len - 1 && count2 < ptr_s2->len - 1)
        {
            temp1 = tolower(*(ptr_s1_end - count1));
            temp2 = tolower(*(ptr_s2_end - count2));

            if (temp1 > temp2)
                return 1;

            if (temp2 > temp1)
                return -1;

            count1++;
            count2++;
        }
    }
    if (count1 == ptr_s1->len - 1)
    {
        if (count2 == ptr_s2->len - 1)
            return 0;

        return -1;
    }
    if (count2 == ptr_s2->len - 1)
        return 1;
}



