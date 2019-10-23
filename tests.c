#include "header.h"

int main(int argc,char* argv[])
{
	// test_swap();
	// test_affiche();
	// test_compare();
	return 0;
}

void test_swap(void)
{
	int nbr_4 = 44;
	int nbr_5 = 55;

	swap(&nbr_4, &nbr_5);
	printf("Nbr_4 = %d : 55\nNbr_5 = %d : 44\n",nbr_4, nbr_5);
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

void test_comparison(void)
{
	int tab[6] = {1,2,3,5,4,6};
	int test_success1 = 0;
	int test_success2 = 0;

	test_success1 = comparison(tab, 6, 2);
	test_success2 = comparison(tab, 6, 3);

	printf("1ère comparaison : valeur plus petite.\nRésultat : ");
	if (test_success1 == NO) printf("Pas d'erreur !\n\n");
	else printf("Une erreur !\n\n");

	printf("2ème comparaison : valeur plus grande.\nRésultat : ");
	if (test_success2 == YES) printf("Pas d'erreur !\n\n");
	else printf("Une erreur !\n\n");
}

void test_InsertionSort(void)
{
	int tab[10] = {1,2,5,6,8,9,0,3,4,7};
	affiche(tab, 10);
	InsertionSort(tab, 10);
	affiche(tab, 10);
	printf("Tableau contentant les 10 1èrs entiers (de 0 à 9)\n\n");
}

void test_merge(void)
{
	int tab[10] = {5,6,7,8,9,1,2,3,4,0};
	int tmp[10];
	int counter;

	merge(tab, tmp, 0, 9, 4, &counter);

	affiche(tmp, 10);

}
