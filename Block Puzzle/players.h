#ifndef PLAYERS_H_INCLUDED
#define PLAYERS_H_INCLUDED
#include <time.h>

typedef struct{
int score;
char name[12];
char date[14];
}player;
void init_top_players(player *top_players);
int check_score(int score,player *top_players);
char * score_date();


#endif // PLAYERS_H_INCLUDED
