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


int compare(int* a, int *b, int n)
//Compare les valeurs de deux tableaux de taille n et vérifie si toutes les valeurs sont identiques.
{
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


long bubble_sort(int* tab, int size)
{
	long to_return = 0;
	for(int rank = 0; rank < size-1;rank++)
  {
		for(int depth = 1 ; depth < size ; depth++)
    {
			to_return++;
			if((tab[depth] < tab[depth-1]))
      {
				swap(tab+depth,tab+depth-1);
			}
		}
	}
	return to_return;
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
