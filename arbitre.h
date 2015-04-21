#include"joueur.h"
void create_map(struct map *self);
void create_square(struct square *self, int x, int y);
void create_piece(struct piece *self, int x, int y);
void delete_piece(struct piece *self);
void delete_square(struct square *self);
void delete_map(struct map *self);
void make_game();
