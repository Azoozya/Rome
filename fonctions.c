#include "header.h"

void swap(int* a, int* b)
//Echange les valeurs stockés dans 2 pointeurs différents (2 cases d'un même tableau)
{
  int c = *a;
  *a = *b;
  *b = c;
}

void affiche(int* a, int n)
//Affiche les valurs d'un tableau
{
	int i;
	for (i = 0 ; i < n ; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n");
}


int compare(int* a, int *b, int n)
//Compare les valeurs de deux tableaux et vérifie si toutes les valeurs sont identiques.
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

long bubble_sort(int* tab,int size)
//Fonction de tri BubbleSort
{
  long to_return = 0;
  for(long depth = 0 ; depth < size ;  depth++)
    {
      long subrank = depth;
      while(comparison(tab,size,subrank) == YES)
        //Test si la valeur actuelle est plus grande que la suivante. Si oui, les deux valeurs sont échangés.
        {
          swap((tab+subrank),(tab+subrank+1));
          subrank++;
          to_return++;
        }
    }
  // to_return retourne le nombre d'échanges effectués pour arriver au tableau finale trié correctement.
  return to_return;
}

int min_ex(int* tab,int size,int floor)
//retourne le plus petit des minorants du tableau passé en argument qui est plus grand qu'une valeur donné.
{
  int to_return = 0;
  long max_rank = size;
  long rank = 0;
  while(rank < max_rank && tab[rank] < floor)
    {
      rank++;
    }
  to_return = tab[rank];
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


void merge(int* tab, int* tmp, int left, int mid, int right, int* cnt)
{
	int i = left, j = mid+1, k =0;
	while(i<= mid && j <= right){
		if(tab[i]<=tab[j]){
			tmp[k++] = tab[i++];
		}
		else
			tmp[k++] = tab[j++];
		(*cnt)++;
	}
	while(i<=mid)
		tmp[k++] = tab[i++];
	while (j<=right)
		tmp[k++]=tab[j++];
	    k--;
	while (k>=0) {
		tab[left+k]=tmp[k];
		k--;
	}
}

int mergeSort(int tab[], int len)
{
	int comparaison=0;
	int *tmp=malloc(len*sizeof(int));
	int currentSize;
	int left;
	for(currentSize=1;currentSize<len;currentSize=2*currentSize){
		for(left=0;left<len-1;left+=2*currentSize){
			int mid= left+currentSize-1;
			int right=min(left+2*currentSize-1,len-1);
			merge(tab,tmp,left,mid,right,&comparaison);
		}
	}
	free(tmp);
	return comparaison;
}
