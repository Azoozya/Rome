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

long my_strlen(int* tab)
{
  long to_return = 0;
  while(tab[to_return] != '\0')
    {
      to_return++;
    }
  return to_return;
}

int comparison(int* tab,long cursor)
{
  if (cursor < my_strlen(tab))
    {
      if(tab[cursor] > tab[cursor+1])
        return YES;
      else
        return NO;
    }
  else
    return NO;
}

long bubble_sort(int* tab)
{
  long to_return = 0;
  long size = my_strlen(tab);
  for(long depth = 0 ; depth < size ;  depth++)
    {
      long subrank = depth;
      while(comparison(tab,subrank) == YES)
        {
          swap((tab+subrank),(tab+subrank+1));
          subrank++;
          to_return++;
        }
    }

  return to_return;
}

void InsertionSort(int* tab, int n){

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


//void merge (int* tab, int* tmp, int left, int mid, int right, int* cnt);
