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
	int nbr_44 = 44;
	int nbr_55 = 55;

	swap(&nbr_44, &nbr_55);

	if(nbr_44 == 55 && nbr_55 == 44) printf("swap() fonctionnel\n\n");
	else printf("swap() non fonctionnel\n\n");
}

void test_affiche(void)
{
	int tab_affiche[10] = {1,2,3,4,5,6,7,8,9,10};
	affiche(tab_affiche, 10);
	printf("Le tableau affiché contient les 10 1ers entiers (1 à 10).\n");
}

void test_compare(void)
{
	int tab1[5] = {1,2,3,4,5};
	int tab2[5] = {1,2,3,4,5};
	int tab3[5] = {1,2,3,5,4};
	int success_compare1;
	int success_compare2;

	success_compare1 = compare(tab1, tab2, 5);
	success_compare2 = compare(tab1, tab3, 5);

	if (success_compare1 == -1 && success_compare2 != -1) printf("compare() fonctionnel\n");
	else printf("compare() non fonctionnel\n");
}

void test_comparison(void)
{
	int tab[6] = {1,2,3,5,4,6};
	int success_comparison1 = 0;
	int success_comparison2 = 0;

	success_comparison1 = comparison(tab, 6, 2);
	success_comparison2 = comparison(tab, 6, 3);

	if (success_comparison1 == NO && success_comparison2 == YES) printf("comparison() fonctionnel\n");
	else printf("comparison() non fonctionnel\n");
}
