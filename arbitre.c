#include"arbitre.h"
void create_map(struct map *self){
	//création d'un plateau
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			create_square(self->all[i][j],i,j); //all => bug
		}	
	}
}
void create_square(struct square *self, int x, int y){
	//création d'une piece
	self->self=calloc(1,sizeof(struct piece));
	create_piece(self->self,x,y);
	if(x<4 || x>5){
		self->water=0;
		self->starter=1;
	}else if(y==2||y==3||y==6||y==7){
		self->water=1;
		self->starter=0;
	}else{
		self->water=0;
		self->starter=0;
	}
}
void create_piece(struct piece *self, int x, int y){
	//création d'une piece
	self->value=0;
	self->pos=NULL;
	self->player=NULL;
}
void update_piece(struct piece *self, int value, char *pos){
    self->value=value;
    self->pos=*pos;
}
void delete_piece(struct piece *self){
	//supression d'une piece
	free(self);
}
void delete_square(struct square *self){
	//supression de map
	delete_piece(self->self);
	free(self);
}
void delete_map(struct map *self){
	//supression de map
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			delete_square(self->all[i][j]);
		}	
	}
	free(self);
}
int main(int argc, char *argv[]){
    struct map *self = calloc(1,sizeof(struct map));
    create_map(self);
    if(fork()==0){
        execvp("./joueur",0);
    }
    wait(0);
    if(fork()==0){
        execvp("./joueur",1);
    }
    wait(0);
    for(;;){
        //TODO pipe
    }
    return 0;
}
