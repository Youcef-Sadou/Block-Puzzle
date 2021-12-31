#ifndef OPTIMIZER_H_INCLUDED
#define OPTIMIZER_H_INCLUDED
#include "piece.h"
typedef struct{
int pos,width;
}gap;
int bot_drop_piece(piece *p,b* grid,int x, int y);
piece* bot_compare_pieces(piece *p,piece *p2,piece *p3);
int bot_check_gaps(b* grid,gap* gap);
int bot_check_tenth_piece(b grid[10][10],int x, int y);
int bot_check_seventh_piece(b grid[10][10],int x, int y);
int bot_check_fourth_piece(b grid[10][10],int x, int y);
int bot_check_ninth_piece(b grid[10][10],int x, int y);
int bot_check_first_piece(b grid[10][10],int x, int y);
int bot_check_second_piece(b grid[10][10],int x, int y);
int bot_check_third_piece(b grid[10][10],int x, int y);
int bot_check_fifth_piece(b grid[10][10],int x, int y);
int bot_check_sixth_piece(b grid[10][10],int x, int y);
int bot_check_eight_piece(b grid[10][10],int x, int y);
piece* PD(piece* p1,piece* p2, piece* p3,b grid[10][10], int t, int v, int w, int x, int y);


#endif // OPTIMIZER_H_INCLUDED
