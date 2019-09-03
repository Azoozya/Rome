#include "header.h"

void swap(int* a, int* b)
{
  int c = *a;
  *a = *b;
  *b = c;
}


void affiche(int* a, int n){
	int i;
	for (i = 0 ; i < n ; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n");
}


int compare(int* a, int *b, int n){
	int i;
	for(i=0; i < n ; i++){
		if (a[i] != b[i]){
			printf("Comparison FAILED at index %d\n\n", i);
			return i;
		}
	}
	printf("Comparison OK\n\n");
	return -1;
}


void merge (int* tab, int* tmp, int left, int mid, int right, int* cnt);
