#include "header.h"

int main(int argc,char* argv[])
{
	test_mergesort();
	test_bubblesort();
	test_swap();
	test_affiche();
	test_compare();
	return 0;
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
	printf("Comparaisons pour tab2 : %d\n",mergeSort(mergetab2,n) );
	affiche(mergetab2, n);
	printf("Comparaisons pour tab3 : %d\n",mergeSort(mergetab3,n) );
	affiche(mergetab3, n);

}


void test_bubblesort(void)
{
	int bubbleref[]  = {3,6,6,7,8,10,14,15,17,19,20,21,23,25,26,28,28,28,32,32,34,35,38,38,39,43,44,46,48,49,50,58,59,62,64,65,69,71,75,79,79,79,81,84,86,89,92,93,97,99};
	int bubbletab1[] = {14,15,92,65,35,89,79,32,38,46,26,43,38,32,79,50,28,84,19,71,69,39,93,75,10,58,20,97,49,44,59,23,07,81,64,06,28,62,8,99,86,28,03,48,25,34,21,17,06,79};
	int bubbletab2[] = {99,97,93,92,89,86,84,81,79,79,79,75,71,69,65,64,62,59,58,50,49,48,46,44,43,39,38,38,35,34,32,32,28,28,28,26,25,23,21,20,19,17,15,14,10,8,7,6,6,3};
	int bubbletab3[] = {3,6,6,7,8,10,14,15,17,19,81,21,23,25,26,28,28,28,32,32,34,35,38,38,39,43,44,46,48,49,50,58,59,62,64,65,69,71,75,79,79,79,20,84,86,89,92,93,97,99};

	int n = sizeof(bubbleref)/sizeof(int);
	printf("Avec BubbleSort\n");
	printf("Comparaisons pour ref : %d\n",bubble_sort(bubbleref,n));
	affiche(bubbleref, n);
	printf("Comparaisons pour tab1 : %d\n",bubble_sort(bubbletab1,n));
	affiche(bubbletab1, n);
	printf("Comparaisons pour tab2 : %d\n",bubble_sort(bubbletab2,n));
	affiche(bubbletab2, n);
	printf("Comparaisons pour tab3 : %d\n",bubble_sort(bubbletab3,n));
	affiche(bubbletab3, n);

}

void test_swap(void)
{
	int nbr_4 = 44;
	int nbr_5 = 55;

	swap(&nbr_4, &nbr_5);
	printf("Nbr_4 = %d\nNbr_5 = %d\n",nbr_4, nbr_5);
}

void test_affiche(void)
{
	int tab_affiche[10] = {1,2,3,4,5,6,7,8,9,10};
	affiche(tab_affiche, 8);
	printf("tab_affiche contient les 10 1ers entiers et 'affiche' est censée afficher les 8 1ers éléments du tab.\n");
}

void test_compare(void)
{
	int tab1[5] = {1,2,3,4,5};
	int tab2[5] = {1,2,3,4,5};
	int tab3[5] = {1,2,3,5,4};

	compare(tab1, tab2, 5);
	printf("Les deux tableaux comparés ont les mêmes valeurs\n\n");

	compare(tab1, tab3, 5);
	printf("Les deux tableaux comparés n'ont pas toutes les mêmes valeurs (4ème valeur (index 3) différente)\n");
}
