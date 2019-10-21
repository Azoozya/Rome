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

long my_strlen(int* tab)
//Calcule la taille d'un tableau avec sentinelle à la fin de ce dernier.
{
  long to_return = 0;
  while(tab[to_return] != '\0')
    {
      to_return++;
    }
  return to_return;
}

int comparison(int* tab,long cursor)
//compare deux valeurs successives d'un même tableau (cursor étant la position de la 1ère valeur à calculer)
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
//Fonction de tri BubbleSort
{
  long to_return = 0;
  long size = my_strlen(tab);
  for(long depth = 0 ; depth < size ;  depth++)
    {
      long subrank = depth;
      while(comparison(tab,subrank) == YES)
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

int min_ex(int* tab,int floor)
//retourne le plus petit des minorants du tableau passé en argument
{
  int to_return = 0;
  long max_rank = my_strlen(tab);
  long rank = 0;
  while(rank < max_rank && tab[rank] < floor)
    {
      rank++;
    }
  to_return = tab[rank];
  return to_return;
}

void merge(int* left,int* right,int* tmp,int* tab)
//fonction d'assemblement de deux tableaux
{
  int buffer =0 ;
  long left_rank = 0;
  long right_rank = 0;
  int min_left = 0;
  int min_right = 0;
  for(long rank = 0; rank < my_strlen(left)+my_strlen(right) ; rank++)
    {
      if (left_rank == my_strlen(left)+1)
        {
          min_right = min_ex(right,min_right);
          right_rank++;
          tmp[rank] = min_right;/* code */
        }
      else if ( right_rank == (my_strlen(right)+1))
        {
          min_left = min_ex(left,min_left);
          left_rank++;
          tmp[rank] = min_left;
        }
      else
        {
          min_left = min_ex(left,min_left);
          min_right = min_ex(right,min_right);
          buffer = min(min_left,min_right);
          if(min_left != 0 && min_right == buffer)
            {
              min_left--;
            }
          else if(min_right != 0 && min_left == buffer)
            {
              min_right--;
            }/* code */
          tmp[rank] = buffer;
        }
    }
  tab = tmp;
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
