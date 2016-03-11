#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "shape.h"

struct shape {
	int x;
	int y;	//coordinates in coordinates system
	char type[20];		//is it square or round?
	char color[20];		
};

void shape_move_to(shape p, int x, int y)	//move object to point(x,y)
{
	p->x = x;
	p->y = y;
}

void shape_move_at(shape p, int x, int y)	//move object at x by x, at y by y
{
	p->x += x;
	p->y += y;
}

void shape_claim(shape p)				//claims its coordinates, type, color
{
	printf("I'm %s\n", p->type);
	printf("My color is %s\n", p->color);
	printf("My location is (%d, %d)\n", p->x, p->y);
}

shape shape_new()						//gives memory and creates object type "shape"
{
	shape p = malloc(sizeof(struct shape));
	p->x = 0;
	p->y = 0;
	strcpy(p->color, "white"); 
	strcpy(p->type, "round");
	return p;
}

void shape_delete(shape p)				//frees memory by deleting object "shape"
{
	free(p);
}

void shape_change_color(shape p, char * new_color)			//changes objects color
{
	strcpy(p->color, new_color);
}

void shape_change_type(shape p, char* new_type)			//changes objects type
{
	strcpy(p->type, new_type);
}

