#ifndef SORT
#define SORT

#include <stdlib.h>

void quick_sort(void* ptr, size_t number_element, size_t size_element, bool (*func_comparison)(void*, void*, size_t));

void swap(void* elem1, void* elem2, size_t size_element);
bool comparison_unsigned(void* elem1, void* elem2, size_t size_element);

#endif
