#include "sort.h"

#include <stdlib.h>

static void swap(void* elem1, void* elem2, size_t size_element);

void quick_sort(void* ptr, size_t number_element, size_t size_element, bool (*func_comparison)(const void*, const void*, size_t))
{
    if (number_element <= 1)
        return;

    int pivot = rand() % (number_element - 1);

    void *left = ptr + size_element;
    void *right = ptr + (number_element - 1) * size_element;

    swap(ptr + pivot * size_element, ptr, size_element);

    while(right > left)
    {
        while(!func_comparison(left, ptr, size_element) && left != right)
            left += size_element;

        while(func_comparison(right, ptr, size_element) && right != left)
            right -= size_element;

        swap(left, right, size_element);
    }


    if (func_comparison(right, ptr, size_element))
        swap(ptr, right - size_element, size_element);

    else
        swap(ptr, right, size_element);

    size_t first_size = ((char*)right - (char*)ptr) / size_element;
    quick_sort(ptr, first_size, size_element, func_comparison);
    quick_sort(right, number_element - first_size, size_element, func_comparison);

}

static void swap(void* elem1, void* elem2, size_t size_element)
{
    char temp;
    for ( int i = 0; i < size_element; i++ )
    {
        temp = *((char*)elem1 + i);
        *((char*)elem1 + i) = *((char*)elem2 + i);
        *((char*)elem2 + i) = temp;
    }
}

