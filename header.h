#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define ERROR 63336
#define NONE 36663
#define YES 333
#define NO 4444
#define SIZETABLE 50
#define min(a,b) a<b?a:b;
void swap(int* a, int* b);
int compare(int* a, int *b, int n);
void affiche(int* a, int n);


int comparison(int* tab,int size,long cursor);
int min_ex(int* tab,int size,int floor);
long bubble_sort(int* tab,int size);
void merge (int* tab, int* tmp, int left, int mid, int right, int* counter);
int mergeSort(int tab[], int len);



void test_bubblesort(void);
void test_mergesort(void);
