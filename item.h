#ifndef ITEM_H_
#define ITEM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

#endif /* ITEM_H_ */