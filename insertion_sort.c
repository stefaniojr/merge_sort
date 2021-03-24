#include "item.h"

void insertion_sort(Item *a, int lo, int hi)
{
    int i, j;
    for (i = lo + 1; i < hi; i++)
        for (j = i; j > lo; j--)
            compexch(a[j - 1], a[j])
}