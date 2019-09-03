#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ERROR 63336
#define NONE 36663

void swap(int* a, int* b);
int compare(int* a, int *b, int n);
void affiche(int* a, int n);
void merge (int* tab, int* tmp, int left, int mid, int right, int* cnt);
