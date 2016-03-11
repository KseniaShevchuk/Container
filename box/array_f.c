#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "array_iter.h"

struct array{
	
	void ** arr;
	int max_N;
	int cur_N;	//first num without data
	
};	//Array

struct iter_array
{
	int num;
}; //Iter

void double_max(Array p);
Array copy_from(Array p, int k, int l);
void copy_forward(Array p, int k);
void copy_back(Array p, int k);

Array array_create(int N)	//creates new array
{
	Array p = malloc(sizeof(struct array));
	p->max_N = N;
	p->arr = malloc(sizeof(void *) * p->max_N);
	p->cur_N = 0;
	return p;
}

void array_delete(Array p)	//delete array
{	
	free(p->arr);
	free(p);
}

void array_insert_k(Array p, int k, const void  *data)	//put data to arr[k] and move other data right
{
	if (k >= p->cur_N)
		array_insert_last(p, data);
	else
		{
			copy_forward(p, k);
			p->arr[k] = data;
			p->cur_N +=1;
		}
}


void array_insert_last(Array p, const void *data)	//put data to last available position in array
{
	if (p->cur_N < p->max_N - 1)
		{
		p->arr[p->cur_N] = data;
		p->cur_N += 1;
		}
	else
		{
		double_max(p);
		p->arr[p->cur_N] = data;
		p->cur_N +=1;
		}
}

void array_insert_first(Array p, const void *data)	//put data to first (zero) position in array
{
	array_insert_k(p, 0, data);
}

void array_delete_k(Array p, int k)	//delete data from arr[k] and move other data left
{
	copy_back(p, k);
}

void array_delete_last(Array p)	//delete data from last position in array
{
	p->arr[p->cur_N-1] = NULL;
	p->cur_N -=1;
}

void array_delete_first(Array p)	//delete data from first (zero) position in array and move other data left
{
	array_delete_k(p, 0);
}

void* array_get_k(Array p, int k)	//takes data from arr[k]
{
	return p->arr[k];
}
/*
void foreach(Array p, void(*function), void* data)
{
	int i;

	for(i = 0; i < p->cur_N; i++)
		function(p, i);
}*/

void double_max(Array p)		//doubles max_N
{
	p->max_N *= 2;
	p->arr = realloc(p->arr, sizeof(void*)*p->max_N);
}

Array copy_from(Array p, int k, int l)	//copies data from p[k]-p[l] to another array
{
	Array tmp = array_create(p->max_N);

	int i;
	for(i = k; i<= l; i++)
		tmp[i] = p[i];

	return tmp;
}

void copy_forward(Array p, int k)	// copies data one box to the right from k position
{
	if(p->cur_N >= p->max_N - 1)
		double_max(p);

	int i;
	for(i = p->cur_N; i>=k; i--)
		p->arr[i+1] = p->arr[i];	
	//p->cur_N +=1;
}

void copy_back(Array p, int k)	// copies data one box to the left to k position
{
	int i;
	for(i = k+1; i < p->max_N; i++)
		p->arr[i-1] = p->arr[i];
		//strcpy(p[i-1], p[i]);
	p->cur_N -=1;
}

int array_size(Array p)
{
	return p->cur_N;
}
/*void array_print(Array p)
{
	int i;

	for(i = 0; i < p->cur_N; i++)
		printf("%p\n", p->arr[i]);
}*/


