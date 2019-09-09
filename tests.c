#include "header.h"
int main(int argc,char* argv[])
{
	test_merge();
	return 0;
}

void test_merge(void)
{
	int *tab,*tmp,*left,*right;

	tab = malloc(10*sizeof(int));
	tmp = malloc(10*sizeof(int));
	left = malloc(5*sizeof(int));
	right = malloc(5*sizeof(int));

	left[0] = 1;
	left[1] = 2;
	left[2] = 5;
	left[3] = 7;
	left[4] = 10;

	right[0] = 3;
	right[1] = 4;
	right[2] = 6;
	right[3] = 8;
	right[4] = 9;

	merge(left,right,tmp,tab);
	printf("[Left] :\n");
	affiche(left,5);
	printf("[Right] :\n");
	affiche(right,5);
	printf("[Merged] :\n");
	affiche(tab,10);

	free(tab);
	free(left);
	free(right);
}
