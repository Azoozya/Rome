#include "header.h"

void swap(int* a, int* b)
//Echange les valeurs stockés dans 2 pointeurs différents (2 cases d'un même tableau)
{
  int c = *a;
  *a = *b;
  *b = c;
}

void affiche(int* a, int n)
//Affiche les valeurs d'un tableau
{
	int i;
	for (i = 0 ; i < n ; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n");
}


int compare(int* tab1, int* tab2, int n)
//Compare les valeurs de deux tableaux de taille n et vérifie si toutes les valeurs sont identiques.
{
	int counter;
	for(counter = 0; counter < n ; counter++)
  {
		if (tab1[counter] != tab2[counter])
      {
			     printf("Comparison FAILED at index %d\n\n", counter);
			     return counter;
		  }
	}
	printf("Comparison OK\n\n");
	return -1;
}

int comparison(int* tab,int size,long cursor)
//compare deux valeurs successives d'un même tableau (cursor étant la position de la 1ère valeur à calculer)
{
  if (cursor < size)
    {
      if(tab[cursor] > tab[cursor+1])
        return YES;
      else
        return NO;
    }
  else
    return NO;
}



void InsertionSort(int* tab, int n)
{
/* C_index pour compare index  // S_index pour Sort Index*/

  int save;
  int S_index = 0;
  for (int C_index = 0; C_index < (n-1); C_index++)
  {
    if (*(tab + C_index) > *(tab+C_index+1))
    {

      save = *(tab+C_index+1);
      S_index = C_index;
      while ((*(tab + S_index) > save) && (S_index >= 0))
      {

        *(tab + S_index + 1) = *(tab + S_index);
        S_index = S_index - 1;
      }
      *(tab + S_index + 1) = save;

    }
  }
}

long bubble_sort(int* tab, int size)
{
	long to_return = 0;
	for(int rank = 0; rank < size-1;rank++)
  {
		for(int depth = 1 ; depth < size ; depth++)
    {
			if((tab[depth] < tab[depth-1]))
      {
				swap(tab+depth,tab+depth-1);
        to_return++;
      }
		}
	}
	return to_return;
}

void merge (int* tab, int* tmp, int left, int mid, int right, int* counter)
{
	int i = left;
  int j = mid+1;
  int k =0;
	while(i <= mid && j <= right)
  {
		if(tab[i] <= tab[j])
			tmp[k++] = tab[i++];

    else
			tmp[k++] = tab[j++];
		(*counter)++;
	}

  while(i<=mid)
		tmp[k++] = tab[i++];

  while (j<=right)
		tmp[k++]=tab[j++];

  k--;

  while (k>=0)
  {
		tab[left+k]=tmp[k];
		k--;
	}
}

int mergeSort(int tab[], int size)
{
	int comparaison=0;
	int* tmp = malloc(size*sizeof(int));
  int currentSize;
	int left;
	for(currentSize = 1 ; currentSize < size ; currentSize = 2*currentSize)
  {
		for(left = 0 ; left < size-1 ; left += 2*currentSize)
    {
			int mid = left+currentSize-1;
			int right = min(left + 2*currentSize-1,size-1);
			merge(tab,tmp,left,mid,right,&comparaison);
		}
	}

	free(tmp);
	return comparaison;
}


void test_insertionsort(void)
{
	int Insertionref[]  = {3,6,6,7,8,10,14,15,17,19,20,21,23,25,26,28,28,28,32,32,34,35,38,38,39,43,44,46,48,49,50,58,59,62,64,65,69,71,75,79,79,79,81,84,86,89,92,93,97,99};
	int Insertiontab1[] = {14,15,92,65,35,89,79,32,38,46,26,43,38,32,79,50,28,84,19,71,69,39,93,75,10,58,20,97,49,44,59,23,07,81,64,06,28,62,8,99,86,28,03,48,25,34,21,17,06,79};
	int Insertiontab2[] = {99,97,93,92,89,86,84,81,79,79,79,75,71,69,65,64,62,59,58,50,49,48,46,44,43,39,38,38,35,34,32,32,28,28,28,26,25,23,21,20,19,17,15,14,10,8,7,6,6,3};
	int Insertiontab3[] = {3,6,6,7,8,10,14,15,17,19,81,21,23,25,26,28,28,28,32,32,34,35,38,38,39,43,44,46,48,49,50,58,59,62,64,65,69,71,75,79,79,79,20,84,86,89,92,93,97,99};

	int n = sizeof(Insertionref)/sizeof(int);
	printf("Avec InsertionSort\n");
	InsertionSort(Insertionref,n);
	affiche(Insertionref, n);

  InsertionSort(Insertiontab1,n);
	affiche(Insertiontab1, n);
	if (-1 == compare(Insertionref,Insertiontab1,n)) printf("comparison successful with tab1\n");
  else printf("comparison failed failed for tab1\n");

	InsertionSort(Insertiontab2,n);
	affiche(Insertiontab2, n);
	if (-1 == compare(Insertionref,Insertiontab2,n)) printf("comparison successful with tab2\n");
  else printf("comparison failed failed for tab2\n");

	InsertionSort(Insertiontab3,n);
	affiche(Insertiontab3, n);
	if (-1 == compare(Insertionref,Insertiontab3,n)) printf("comparison successful with tab3\n");
  else printf("comparison failed failed for tab3\n");

}

void test_mergesort(void)
{
	int mergeref[]  = {3,6,6,7,8,10,14,15,17,19,20,21,23,25,26,28,28,28,32,32,34,35,38,38,39,43,44,46,48,49,50,58,59,62,64,65,69,71,75,79,79,79,81,84,86,89,92,93,97,99};
	int mergetab1[] = {14,15,92,65,35,89,79,32,38,46,26,43,38,32,79,50,28,84,19,71,69,39,93,75,10,58,20,97,49,44,59,23,07,81,64,06,28,62,8,99,86,28,03,48,25,34,21,17,06,79};
	int mergetab2[] = {99,97,93,92,89,86,84,81,79,79,79,75,71,69,65,64,62,59,58,50,49,48,46,44,43,39,38,38,35,34,32,32,28,28,28,26,25,23,21,20,19,17,15,14,10,8,7,6,6,3};
	int mergetab3[] = {3,6,6,7,8,10,14,15,17,19,81,21,23,25,26,28,28,28,32,32,34,35,38,38,39,43,44,46,48,49,50,58,59,62,64,65,69,71,75,79,79,79,20,84,86,89,92,93,97,99};

	int n = sizeof(mergeref)/sizeof(int);
	printf("Avec mergeSort\n");
	printf("Comparaisons pour ref : %d\n",mergeSort(mergeref,n) );
	affiche(mergeref, n);
	printf("Comparaisons pour tab1 : %d\n",mergeSort(mergetab1,n) );
	affiche(mergetab1, n);
	compare(mergeref,mergetab1,n);
	printf("Comparaisons pour tab2 : %d\n",mergeSort(mergetab2,n) );
	affiche(mergetab2, n);
	compare(mergeref,mergetab2,n);
	printf("Comparaisons pour tab3 : %d\n",mergeSort(mergetab3,n) );
	affiche(mergetab3, n);
	compare(mergeref,mergetab3,n);

}

void test_bubblesort(void)
{
	int bubbleref[]  = {3,6,6,7,8,10,14,15,17,19,20,21,23,25,26,28,28,28,32,32,34,35,38,38,39,43,44,46,48,49,50,58,59,62,64,65,69,71,75,79,79,79,81,84,86,89,92,93,97,99};
	int bubbletab1[] = {14,15,92,65,35,89,79,32,38,46,26,43,38,32,79,50,28,84,19,71,69,39,93,75,10,58,20,97,49,44,59,23,07,81,64,06,28,62,8,99,86,28,03,48,25,34,21,17,06,79};
	int bubbletab2[] = {99,97,93,92,89,86,84,81,79,79,79,75,71,69,65,64,62,59,58,50,49,48,46,44,43,39,38,38,35,34,32,32,28,28,28,26,25,23,21,20,19,17,15,14,10,8,7,6,6,3};
	int bubbletab3[] = {3,6,6,7,8,10,14,15,17,19,81,21,23,25,26,28,28,28,32,32,34,35,38,38,39,43,44,46,48,49,50,58,59,62,64,65,69,71,75,79,79,79,20,84,86,89,92,93,97,99};

	int n = sizeof(bubbleref)/sizeof(int);
	printf("Avec BubbleSort\n");
	printf("Comparaisons pour ref : %ld\n",bubble_sort(bubbleref,n));
	affiche(bubbleref, n);
	printf("Comparaisons pour tab1 : %ld\n",bubble_sort(bubbletab1,n));
	affiche(bubbletab1, n);
	compare(bubbleref,bubbletab1,n);
	printf("Comparaisons pour tab2 : %ld\n",bubble_sort(bubbletab2,n));
	affiche(bubbletab2, n);
	compare(bubbleref,bubbletab2,n);
	printf("Comparaisons pour tab3 : %ld\n",bubble_sort(bubbletab3,n));
	affiche(bubbletab3, n);
	compare(bubbleref,bubbletab2,n);

}
