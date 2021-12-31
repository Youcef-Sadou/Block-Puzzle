#include "piece.h"
#include "game_over.h"
#include "optimizer.h"
piece* bot_compare_pieces(piece *p,piece *p2,piece *p3){
//we make the comparision based on the width of the first line in the piece
int cpt1 = 0;
for (int k=0;k<3;k++){
    if(p->blocks[0][k].filled==1){
        cpt1++;
    }
}
int cpt2 = 0;
for (int k=0;k<3;k++){
    if(p2->blocks[0][k].filled==1){
        cpt2++;
    }
}
int cpt3 = 0;
for (int k=0;k<3;k++){
    if(p3->blocks[0][k].filled==1){
        cpt3++;
    }
}
int result = cpt1;

if (cpt2 > result){
  result = cpt2;
  }

if (cpt3 > result){
  result = cpt3;
}

if(result==cpt1){
    p->bw = result;
    return p;
}
if(result==cpt2){
    p2->bw = result;
    return p2;
}
if(result==cpt3){
    p3->bw = result;
    return p3;
}

}











int bot_drop_piece(piece *p,b* grid,int x, int y)
{
//here we already assume we can drop it

for(int l=0;l<5;l++)
    for(int k=0;k<3;k++){
        if(p->blocks[l][k].filled == 1 ){
            (grid+ (x*10) +y +(l*10)+k )->filled = 1;
            (grid+ (x*10) +y +(l*10)+k )->color = p->color;

        }


    }

for(int x=0; x<5; x++)
        {
            for(int y=0; y<3; y++)
            {
                p->blocks[x][y].filled=0;

            }
        }

return 1;
}






int bot_check_gaps(b* grid,gap* g){
int f=0;
int j;
while( ((grid+f)->filled == 1) && f<=8 ){
    f++;
}
j = f;
while((grid+j)->filled == 0 && j<9){
    j++;
}
if (j==9){
    return 0;
}
else{
    g->pos = f;
    g->width = (j-f);
    return 1;
}


}





int bot_check_tenth_piece(b grid[10][10],int x, int y){
int bot_tenthpiece_dead = 1;
              if( (x+2<10) && (y+2<10)){
            if( (grid[x][y].filled==0) && (grid[x+1][y].filled==0) && (grid[x+2][y].filled==0) && (grid[x][y+1].filled==0) && (grid[x+1][y+1].filled==0) && (grid[x+2][y+1].filled==0) && (grid[x][y+2].filled==0) && (grid[x+1][y+2].filled==0) && (grid[x+2][y+2].filled==0) ){
                bot_tenthpiece_dead = 0;
            }
              }
return bot_tenthpiece_dead;
}




int bot_check_seventh_piece(b grid[10][10],int x, int y){
int bot_seventhpiece_dead = 1;
  if( (x+4<10) && (y<10)){
            if( (grid[x][y].filled == 0) && (grid[x+1][y].filled==0) && (grid[x+2][y].filled==0) && (grid[x+3][y].filled==0) && (grid[x+4][y].filled==0) ){
                bot_seventhpiece_dead = 0;
            }
  }
return bot_seventhpiece_dead;
}




int bot_check_fourth_piece(b grid[10][10],int x, int y){
int bot_fourthpiece_dead = 1;
if( (x+1<10) && (y+1<10)){
            if( (grid[x][y].filled == 0) && (grid[x+1][y].filled==0) && (grid[x][y+1].filled==0) && (grid[x+1][y+1].filled==0 ) ){
                bot_fourthpiece_dead = 0;
            }
}
return bot_fourthpiece_dead;
}




int bot_check_ninth_piece(b grid[10][10],int x, int y){
int bot_ninthpiece_dead = 1;
if( (x+2<10) && (y+1<10)){
            if( (grid[x][y].filled == 0) && (grid[x][y+1].filled==0) && (grid[x+1][y+1].filled==0) && (grid[x+2][y].filled==0) && (grid[x+2][y+1].filled==0) ){
                bot_ninthpiece_dead = 0;
            }
}
return bot_ninthpiece_dead;
}




int bot_check_first_piece(b grid[10][10],int x, int y){
int bot_firstpiece_dead = 1;
if((y+1<10)){
            if( (grid[x][y].filled == 0) && (grid[x][y+1].filled==0) ) {
                bot_firstpiece_dead = 0;
            }
}
return bot_firstpiece_dead;
}



int bot_check_second_piece(b grid[10][10],int x, int y){
int bot_secondpiece_dead = 1;
  if((y+2<10)){
            if( (grid[x][y].filled == 0) && (grid[x][y+1].filled==0) && (grid[x][y+2].filled==0) ){
                bot_secondpiece_dead = 0;
            }
  }
return bot_secondpiece_dead;
}




int bot_check_third_piece(b grid[10][10],int x, int y){
int bot_thirdpiece_dead = 1;
if((x+1<10) && (y+1<10)){
            if( (grid[x][y].filled == 0) && (grid[x][y+1].filled==0) && (grid[x+1][y+1].filled==0) ){
                bot_thirdpiece_dead = 0;
            }
}
return bot_thirdpiece_dead;
}


int bot_check_fifth_piece(b grid[10][10],int x, int y){
int bot_fifthpiece_dead = 1;
 if((x+2<10) && (y+1<10)){
            if( (grid[x][y].filled == 0) && (grid[x+1][y].filled==0) && (grid[x+2][y].filled==0) && (grid[x+1][y+1].filled==0) ){
                bot_fifthpiece_dead = 0;
            }
 }
return bot_fifthpiece_dead;

}


int bot_check_sixth_piece(b grid[10][10],int x, int y){
int bot_sixthpiece_dead = 1;
if((x+3<10) && (y<10)){
            if( (grid[x][y].filled == 0) && (grid[x+1][y].filled==0) && (grid[x+2][y].filled==0) && (grid[x+3][y].filled==0) ){
                bot_sixthpiece_dead = 0;
            }
}
return bot_sixthpiece_dead;
}




int bot_check_eight_piece(b grid[10][10],int x, int y){

int bot_eightpiece_dead = 1;
        if((x+2<10) && (y+2<10)){
            if( (grid[x][y].filled == 0) && (grid[x][y+1].filled==0) && (grid[x][y+2].filled==0) && (grid[x+1][y+2].filled==0) && (grid[x+2][y+2].filled==0) ){
            bot_eightpiece_dead = 0;
            }
        }
return bot_eightpiece_dead;
}

int bot_check_zero_piece(b grid[10][10],int x, int y){

int bot_zeropiece_dead = 1;
        if((x<10) && (y<10)){
            if( (grid[x][y].filled == 0) ){
            bot_zeropiece_dead = 0;
            }
        }
return bot_zeropiece_dead;
}









piece* PD(piece* p1,piece* p2, piece* p3,b grid[10][10], int t, int v, int w, int x, int y){

piece *bp;
int zero_piece_dead = bot_check_zero_piece(grid,x,y);
int firstpiece_dead = bot_check_first_piece(grid,x,y);
int secondpiece_dead = bot_check_second_piece(grid,x,y);
int thirdpiece_dead = bot_check_third_piece(grid,x,y);
int fifthpiece_dead = bot_check_fifth_piece(grid,x,y);
int sixthpiece_dead = bot_check_sixth_piece(grid,x,y);
int eightpiece_dead = bot_check_eight_piece(grid,x,y);
int ninthpiece_dead = bot_check_ninth_piece(grid,x,y);
int tenthpiece_dead = bot_check_tenth_piece(grid,x,y);
int seventhpiece_dead = bot_check_seventh_piece(grid,x,y);
int fourthpiece_dead = bot_check_fourth_piece(grid,x,y);



switch (t){
    case 0:
        if(zero_piece_dead==1){
            p1->d = 1;
        }else{
            p1->d = 0;
        }
        break;

    case 1:
        if(firstpiece_dead==1){
            p1->d = 1;

        }else{
            p1->d = 0;
        }
        break;
    case 2:
        if(secondpiece_dead==1){
            p1->d = 1;

        }else{
            p1->d = 0;
        }
        break;
    case 3:
        if(thirdpiece_dead==1){
            p1->d = 1;

        }else{
            p1->d = 0;
        }
        break;
    case 4:
        if(fourthpiece_dead==1){
            p1->d = 1;

        }else{
            p1->d = 0;
        }
        break;
    case 5:
        if(fifthpiece_dead==1){
            p1->d = 1;

        }else{
            p1->d = 0;
        }
        break;
    case 6:
        if(sixthpiece_dead==1){
            p1->d = 1;

        }else{
            p1->d = 0;
        }
        break;
    case 7:
        if(seventhpiece_dead==1){
            p1->d = 1;

        }else{
            p1->d = 0;
        }
        break;
    case 8:
        if(eightpiece_dead==1){
            p1->d = 1;

        }else{
            p1->d = 0;
        }
        break;
    case 9:
        if(ninthpiece_dead==1){
            p1->d = 1;

        }else{
            p1->d = 0;
        }
        break;
    case 10:
        if(tenthpiece_dead==1){
            p1->d = 1;

        }else{
            p1->d = 0;
        }
        break;
    default:

        break;
    }


switch (v){
    case 0:
        if(zero_piece_dead==1){
            p2->d = 1;
        }else{
            p2->d = 0;
        }
        break;
    case 1:
        if(firstpiece_dead==1){
            p2->d = 1;

        }else{
            p2->d = 0;
        }
        break;
    case 2:
        if(secondpiece_dead==1){
            p2->d = 1;

        }else{
            p2->d = 0;
        }
        break;
    case 3:
        if(thirdpiece_dead==1){
            p2->d = 1;

        }else{
            p2->d = 0;
        }
        break;
    case 4:
        if(fourthpiece_dead==1){
            p2->d = 1;

        }else{
            p2->d = 0;
        }
        break;
    case 5:
        if(fifthpiece_dead==1){
            p2->d = 1;

        }else{
            p2->d = 0;
        }
        break;
    case 6:
        if(sixthpiece_dead==1){
            p2->d = 1;

        }else{
            p2->d = 0;
        }
        break;
    case 7:
        if(seventhpiece_dead==1){
            p2->d = 1;

        }else{
            p2->d = 0;
        }
        break;
    case 8:
        if(eightpiece_dead==1){
            p2->d = 1;

        }else{
            p2->d = 0;
        }
        break;
    case 9:
        if(ninthpiece_dead==1){
            p2->d = 1;

        }else{
            p2->d = 0;
        }
        break;
    case 10:
        if(tenthpiece_dead==1){
            p2->d = 1;

        }else{
            p2->d = 0;
        }
        break;
    default:
            p2->d = 0;
        break;
    }

switch (w){
    case 0:
        if(zero_piece_dead==1){
            p3->d = 1;
        }else{
            p3->d = 0;
        }
        break;
    case 1:
        if(firstpiece_dead==1){
            p3->d = 1;

        }else{
            p3->d = 0;
        }
        break;
    case 2:
        if(secondpiece_dead==1){
            p3->d = 1;

        }else{
            p3->d = 0;
        }
        break;
    case 3:
        if(thirdpiece_dead==1){
            p3->d = 1;

        }else{
            p3->d = 0;
        }
        break;
    case 4:
        if(fourthpiece_dead==1){
            p3->d = 1;

        }else{
            p3->d = 0;
        }
        break;
    case 5:
        if(fifthpiece_dead==1){
            p3->d = 1;

        }else{
            p3->d = 0;
        }
        break;
    case 6:
        if(sixthpiece_dead==1){
            p3->d = 1;

        }else{
            p3->d = 0;
        }
        break;
    case 7:
        if(seventhpiece_dead==1){
            p3->d = 1;

        }else{
            p3->d = 0;
        }
        break;
    case 8:
        if(eightpiece_dead==1){
            p3->d = 1;

        }else{
            p3->d = 0;
        }
        break;
    case 9:
        if(ninthpiece_dead==1){
            p3->d = 1;

        }else{
            p3->d = 0;
        }
        break;
    case 10:
        if(tenthpiece_dead==1){
            p3->d = 1;

        }else{
            p3->d = 0;
        }
        break;
    default:

        break;
    }


if (p1->d==1 && p2->d==1 && p3->d==1){
    return NULL;
}
if (p1->d==0 && p2->d==0 && p3->d==0){
    bp = bot_compare_pieces(p1,p2,p3);
    return bp;
}

if(p1->d==0 && p2->d==1 && p3->d==1){
    return p1;
}

if(p1->d==1 && p2->d==0 && p3->d==1){
    return p2;
}

if(p1->d==1 && p2->d==1 && p3->d==0){
    return p3;
}


if(p1->d==0 && p2->d==1 && p3->d==0){
    if((p1->bw)>(p3->bw)){
    return p1;
    }else{
    return p3;
    }
}



if(p1->d==0 && p2->d==0 && p3->d==1){
    if((p1->bw)>(p2->bw)){
    return p1;
    }else{
    return p2;
    }
}


if(p1->d==1 && p2->d==0 && p3->d==0){
    if((p3->bw)>(p2->bw)){
    return p3;
    }else{
    return p2;
    }
}




return PD;

}
