// structs; similar to object oriented programming
#include <stdlib.h>
#include <stdio.h>
typedef struct _table {
	double length, width;
	int legs;
} table;

struct foo{
	int a, b, c;
};

void print_table_stats(table t);
int main() {
	table desk;
	desk.length = 5.5;
	desk.width = 1.5;
	desk.legs = 2;

	struct foo bar;

	printf("size of table: %lu\n", sizeof(table));
	printf("size of int: %lu\n", sizeof(int));
        printf("size of long: %lu\n", sizeof(long));
	printf("size of double: %lu\n", sizeof(double));

	double * a = (double *)(&desk);
	printf("%f\n", a[0]);
	printf("%f\n", a[1]);
	printf("%f\n", a[2]);

	// breaking up 64-bit int into parts
	int * b = (int *)(&desk);
	for(int i=0; i<6; i++)
		printf("%d\n", b[i]);
	print_table_stats(desk);

	return 0;
}

void print_table_stats(table t){
	printf("L %f, W %f, L %d\n", t.length, t.width, t.legs);
}
