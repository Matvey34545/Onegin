#include <stdio.h>
#include "sort.h"

int main()
{
    int N = 0;
    scanf("%d", &N);
    int s[N] = {};
    for (int i = 0; i < N; i++)
        scanf("%d", s + i);
    quick_sort(s, N, sizeof(int), comparison_unsigned);
    for (int i = 0; i < N; i++)
        printf("%d ", *(s + i));
}
