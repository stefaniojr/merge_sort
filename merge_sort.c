#include "item.h"

#define CUTOFF 10

extern void insertion_sort(Item *a, int lo, int hi);

void merge(Item *a, Item *aux, int lo, int mid, int hi)
{
    for (int k = lo; k <= hi; k++)
        aux[k] = a[k]; // Copy array.
    int i = lo, j = mid + 1;

    for (int k = lo; k <= hi; k++)
    {
        if (i > mid)
            a[k] = aux[j++];
        else if (j > hi)
            a[k] = aux[i++];
        else if (less(aux[j], aux[i]))
            a[k] = aux[j++];
        else
            a[k] = aux[i++];
    }
}
void merge_sort_top_down(Item *a, Item *aux, int lo, int hi)
{
    if (hi <= lo)
        return;

    if (hi <= lo + CUTOFF - 1)
    {
        insertion_sort(a, lo, hi);
        return;
    }
    int mid = lo + (hi - lo) / 2; // Avoid overflow.
    merge_sort_top_down(a, aux, lo, mid);
    merge_sort_top_down(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
}

void merge_sort_top_down_cut_off(Item *a, Item *aux, int lo, int hi)
{
    if (hi <= lo + CUTOFF - 1)
    {
        insertion_sort(a, lo, hi);
        return;
    }
    int mid = lo + (hi - lo) / 2; // Avoid overflow.
    merge_sort_top_down_cut_off(a, aux, lo, mid);
    merge_sort_top_down_cut_off(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
}

void merge_sort_top_down_merge_skip(Item *a, Item *aux, int lo, int hi)
{
    if (hi <= lo)
        return;

    int mid = lo + (hi - lo) / 2; // Avoid overflow.
    merge_sort_top_down_merge_skip(a, aux, lo, mid);
    merge_sort_top_down_merge_skip(a, aux, mid + 1, hi);
    if (!less(a[mid + 1], a[mid]))
        return;
    merge(a, aux, lo, mid, hi);
}

void merge_sort_top_down_cut_off_merge_skip(Item *a, Item *aux, int lo, int hi)
{
    if (hi <= lo + CUTOFF - 1)
    {
        insertion_sort(a, lo, hi);
        return;
    }
    int mid = lo + (hi - lo) / 2; // Avoid overflow.
    merge_sort_top_down_cut_off_merge_skip(a, aux, lo, mid);
    merge_sort_top_down_cut_off_merge_skip(a, aux, mid + 1, hi);
    if (!less(a[mid + 1], a[mid]))
        return;
    merge(a, aux, lo, mid, hi);
}

#define SZ2 (sz + sz)
#define MIN(X, Y) ((X < Y) ? (X) : (Y))

extern void merge_sort_bottom_up(Item *a, Item *aux, int lo, int hi)
{
    int N = (hi - lo) + 1;
    int y = N - 1;

    for (int sz = 1; sz < N; sz = SZ2)
    {
        for (int lo = 0; lo < N - sz; lo += SZ2)
        {
            int x = lo + SZ2 - 1;
            merge(a, aux, lo, lo + sz - 1, MIN(x, y));
        }
    }
}