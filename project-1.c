#include <stdlib.h>
#include <stdio.h>

typedef struct intvec {
	int * vec;
	int size;
	int capacity;
} intvec; //struct to create a vector

void iv_init(intvec * self); //constructor
void iv_cleanup(intvec * self);
void iv_push(intvec* self, int val);
int iv_get(intvec self, int idx, int * val); //passing pointer is consistent, but not necessarily safer
int iv_set(intvec self, int idx, int val); //no pointers since no vars are being directly modified; pointers are acceptable though

int main(){
	//create an intvec struct (or object)
	intvec v;
	iv_init(&v); //address of v to iv_init

	iv_push(&v, 5);
	int result;
	if(iv_get(v, 0, &result))
		printf("Value at index 0: %d\n", result);

	iv_cleanup(&v);

	return 0;
}

void iv_init(intvec * self){
	(*self).size = 0; //dereference pointer (turn *self into it's stored value) to use .; try to use arrow (->)
	self->capacity = 2; //use arrow oerator; follow the pointer to get capacity of 2
	self -> vec = (int*) calloc(self->capacity /*capacity is still 2*/, sizeof(int));
}

void iv_cleanup(intvec * self){
	free(self->vec);
	self->vec = NULL;
	self->size = 0;
	self->capacity = 0;
}

void iv_push(intvec* self, int val){
	if(self->size == self->capacity){
		self->capacity *= 2; //capcity is now 4; double of original size
		//
		self->vec = (int*)realloc(self->vec, self->capacity * sizeof(int));
	}
	self->vec[self->size] = val;
	self->size+=1;
}

int iv_get(intvec self, int idx, int * val){
	if (idx < 0 || idx >= self.size)
		return 0;
	*val = self.vec[idx];
	return 1;
}

int iv_set(intvec self, int idx, int val){
	if (idx < 0 || idx >= self.size)
		return 0;
	self.vec[idx] = val;
	return 1;
}
