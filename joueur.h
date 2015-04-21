#include<stdio.h>
#include<stdlib.h>
struct piece {
	int value;
	char *pos;
	int player;
};
struct square {
	struct piece *self;
	int starter;
	int water;
};
struct map {
	struct square **all;
};
