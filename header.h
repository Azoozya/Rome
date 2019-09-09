#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define ERROR 63336
#define NONE 36663
#define YES 333
#define NO 4444
#define min(a,b) a<b?a:b;
void swap(int* a, int* b);
int compare(int* a, int *b, int n);
void affiche(int* a, int n);
//void merge (int* tab, int* tmp, int left, int mid, int right, int* cnt);

int comparison(int* tab,long cursor);
long my_strlen(int* tab);
int min_ex(int* tab,int floor);
void merge(int* left,int* right,int* tmp,int* tab);
long bubble_sort(int* tab);





void test_merge(void);
