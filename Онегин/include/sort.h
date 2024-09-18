#ifndef SORT
#define SORT

#include <stdlib.h>

void quick_sort(void* ptr, size_t number_element, size_t size_element, int (*func_comparison)(const void*, const void*));
void random_sort(void* ptr, size_t number_element, size_t size_element, int (*func_comparison)(const void*, const void*));

#endif
