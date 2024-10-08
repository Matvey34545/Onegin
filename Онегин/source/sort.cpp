#include "sort.h"

#include <stdlib.h>
#include <stdio.h>

static void swap(void* elem1, void* elem2, size_t size_element);

void quick_sort(void* ptr, size_t number_element, size_t size_element, int (*func_comparison)(const void*, const void*))
{
    if (number_element <= 1)
        return;

    int pivot = rand() % number_element;

    void *left = ptr + size_element;
    void *right = ptr + (number_element - 1) * size_element;

    swap(ptr + pivot * size_element, ptr, size_element);

    while(right > left)
    {
        while(func_comparison(left, ptr) < 0 && left != right)
            left += size_element;

        while(func_comparison(right, ptr) >= 0 && right != left)
            right -= size_element;

        swap(left, right, size_element);
    }


    if (func_comparison(right, ptr) >= 0)
        swap(ptr, right - size_element, size_element);

    else
        swap(ptr, right, size_element);

    size_t first_size = ((char*)right - (char*)ptr) / size_element;
    quick_sort(ptr, first_size, size_element, func_comparison);
    quick_sort(right, number_element - first_size, size_element, func_comparison);

}

void random_sort(void* ptr, size_t number_element, size_t size_element, int (*func_comparison)(const void*, const void*))
{
    printf("This sorting is the most accurate. Unfortunately,"
           " the speed of work will have to pay for accuracy. "
           "In the meantime, make yourself some tea and wait. The result will surprise you.\n");

    for (long long int i = 0; i < number_element * number_element * number_element; i++)
    {
        int number1 = rand() % number_element;
        int number2 = rand() % number_element;
        if (func_comparison(ptr + number1 * size_element, ptr + number2 * size_element) == 1)
            swap(ptr + number1 * size_element, ptr + number2 * size_element, size_element);
    }
}

static void swap(void* elem1, void* elem2, size_t size_element)
{
    const int size_long_long_int = sizeof(long long int);
    while(size_element >= size_long_long_int)
    {
        long long int long_temp = 0;
        long_temp = *((long long int*)elem1);
        *((long long int*)elem1) = *((long long int*)elem2);
        *((long long int*)elem2) = long_temp;
        size_element -= size_long_long_int;
        elem1 += size_long_long_int;
        elem2 += size_long_long_int;
    }

    while(size_element > 0)
    {
        char temp = '\0';
        temp = *((char*)elem1);
        *((char*)elem1) = *((char*)elem2);
        *((char*)elem2) = temp;
        size_element -= 1;
        elem1 += 1;
        elem2 += 1;
    }
}

