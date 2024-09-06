#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

bool MyStrcpm(const char *s1, const char *s2);


bool MyStrcpm(const char *s1, const char *s2)
{
    char temp1 = 'a';
    char temp2 = 'a';

    while( *s1 != '\0' && *s2 != '\0' )
    {
        while(!isalpha(*s1) && *s1 != '\0')
            s1++;

        while(!isalpha(*s2) && *s2 != '\0')
            s2++;

        if (*s1 != '\0' && *s2 != '\0')
        {
            temp1 = tolower(*s1);
            temp2 = tolower(*s2);

            if (temp1 > temp2)
                return true;

            if (temp2 > temp1)
                return false;

            s1++;
            s2++;
        }
    }
    if (*s1 == '\0')
    {
        if (*s2 == '\0')
            return true;

        return false;
    }
    if (*s2 == '\0')
        return true;
}

