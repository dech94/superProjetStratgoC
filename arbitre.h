#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
	struct square all[10][10];
};
void create_map(struct map *self);
void create_square(struct square *self, int x, int y);
void create_piece(struct piece *self, int x, int y);
void delete_piece(struct piece *self);
void delete_square(struct square *self);
void delete_map(struct map *self);
