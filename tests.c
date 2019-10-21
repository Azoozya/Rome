#include "header.h"

int main(int argc,char* argv[])
{
	// test_merge();
	test_bubblesort();
	test_min_ex();
	return 0;
}

void test_min_ex(void)
{
	int table[] = {2,3,4,1};
	int out[] = {0,0,0,0};
	int floor = 0;
	for(int rank = 0 ; rank < 4 ; rank++)
		{
			floor = min_ex(table,4,floor);
			out[rank] = floor;
		}
	printf("Table[0] = %d:2\nTable[1] = %d:3\nTable[2] = %d:4\nTable[3] = %d:1\n",out[0],out[1],out[2],out[3]);
}

// void test_merge(void)
// {
// 	int *tab,*tmp,*left,*right;
//
// 	tab = malloc(10*sizeof(int));
// 	tmp = malloc(10*sizeof(int));
// 	left = malloc(5*sizeof(int));
// 	right = malloc(5*sizeof(int));
//
// 	left[0] = 1;
// 	left[1] = 2;
// 	left[2] = 5;
// 	left[3] = 7;
// 	left[4] = 10;
//
// 	right[0] = 3;
// 	right[1] = 4;
// 	right[2] = 6;
// 	right[3] = 8;
// 	right[4] = 9;
//
// 	merge(left,SIZETABLE,right,SIZETABLE,tmp,tab);
// 	printf("[Left] :\n");
// 	affiche(left,5);
// 	printf("[Right] :\n");
// 	affiche(right,5);
// 	printf("[Merged] :\n");
// 	affiche(tab,10);
//
// 	free(tab);
// 	free(tmp);
// 	free(left);
// 	free(right);
// }


void test_bubblesort(void)
{
	int ref[]  = {3,6,6,7,8,10,14,15,17,19,20,21,23,25,26,28,28,28,32,32,34,35,38,38,39,43,44,46,48,49,50,58,59,62,64,65,69,71,75,79,79,79,81,84,86,89,92,93,97,99};
	int tab1[] = {14,15,92,65,35,89,79,32,38,46,26,43,38,32,79,50,28,84,19,71,69,39,93,75,10,58,20,97,49,44,59,23,07,81,64,06,28,62,8,99,86,28,03,48,25,34,21,17,06,79};
	int tab2[] = {99,97,93,92,89,86,84,81,79,79,79,75,71,69,65,64,62,59,58,50,49,48,46,44,43,39,38,38,35,34,32,32,28,28,28,26,25,23,21,20,19,17,15,14,10,8,7,6,6,3};
	int tab3[] = {3,6,6,7,8,10,14,15,17,19,81,21,23,25,26,28,28,28,32,32,34,35,38,38,39,43,44,46,48,49,50,58,59,62,64,65,69,71,75,79,79,79,20,84,86,89,92,93,97,99};

	int TailleTab = SIZETABLE;

	long Nbr_Swap1 = bubble_sort(tab1,SIZETABLE);
	long Nbr_Swap2 = bubble_sort(tab2,SIZETABLE);
	long Nbr_Swap3 = bubble_sort(tab3,SIZETABLE);

	printf("Résultat Bubble Sort tableau 1 (random):\n\n");
	affiche(tab1, TailleTab);
	printf("Nbr de changements de places effectués = %ld \n", Nbr_Swap1);
	compare(ref, tab1, TailleTab);

	printf("Résultat Bubble Sort tableau 2 (Décroissant):\n");
	affiche(tab2, TailleTab);
	printf("Nbr de changements de places effectués = %ld \n", Nbr_Swap2);
	compare(ref, tab2, TailleTab);

	printf("Résultat Bubble Sort tableau 3 (1 seul swap):\n");
	affiche(tab3, TailleTab);
	printf("Nbr de changements de places effectués = %ld \n", Nbr_Swap3);
	compare(ref, tab3, TailleTab);

}
