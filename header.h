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
//void merge (int* tab, int* tmp, int left, int mid, int right, int* cnt);

int comparison(int* tab,int size,long cursor);
int min_ex(int* tab,int size,int floor);
void merge(int* left,int sizeL,int* right,int sizeR,int* tmp,int* tab);
long bubble_sort(int* tab,int size);




void test_bubblesort(void);
void test_merge(void);
void test_min_ex(void);
