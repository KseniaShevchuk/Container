#include <stdio.h>
#include "array_iter.h"

int main()
{
	Array p = array_create(10);
	int i;

	//p->m->insert_k(p, 1, "one");
	
		
	array_insert_k(p, 1, "one");	
	array_insert_k(p, 2, "two");
	array_insert_k(p, 3, "three");
	array_insert_k(p, 4, "four");
	array_insert_k(p, 5, "five");
	array_insert_k(p, 6, "six");
	array_insert_k(p, 7, "seven");
	array_insert_k(p, 8, "eight");
	array_insert_k(p, 9, "nine");

	array_insert_first(p, "here");
	array_insert_k(p, 6, "here_two");
	array_insert_k(p, 15, "here_three");

	printf("size = %d\n", array_size(p));


	for(i = 0; i < 20; i++)
		printf("%d = %s\n", i, (char*)array_get_k(p, i));
		
	printf("\n");

	array_delete_last(p);
	array_delete_k(p, 4);
	array_delete_first(p);
	printf("size = %d\n", array_size(p));
	for(i = 0; i < 20; i++)
		printf("%d = %s\n", i, (char*)array_get_k(p, i));

	array_delete(p);	
	return 0;
}
