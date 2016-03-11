typedef struct shape* shape;

void shape_move_to(shape, int x, int y);	//move object to point(x,y)
void shape_move_at(shape, int x, int y);	//move object at x by x, at y by y
void shape_claim(shape);				//claims its coordinates, type, color
shape shape_new();						//gives memory and creates object type "shape"
void shape_delete(shape);				//frees memory by deleting object "shape"
void shape_change_color(shape p, char * new_color);			//changes objects color
void shape_change_type(shape p, char* new_type);			//changes objects type
