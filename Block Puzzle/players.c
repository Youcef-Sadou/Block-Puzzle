#include "players.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
void init_top_players(player *top_players){
int i ;
for (i=0; i<5;i++){
    (top_players+i)->score = 0;
}
}

char * score_date(){
    struct tm *pt;
    time_t t;
    char date[13];
    t = time(NULL);
    pt = localtime(&t);

    strftime(date,13,"%d/%m/%Y",pt);
    return 0;


}





int check_score(int score,player *top_players){
int i,j;
for ( i=0;i<5;i++){
    if(score> (top_players+i)->score ){
        //this loop right here is not working
        j = 4;
        while(j>=i){
        //for(j=3;j<i;j--){
            (top_players+j)->score = (top_players+(j-1))->score;
            //(top_players+j)->score = (top_players+(j-1))->score;
            strcpy((top_players+j)->name,(top_players+(j-1))->name);
            strcpy((top_players+j)->date,(top_players+(j-1))->date);
        j = j-1;
        //}
        //this is working
}
        struct tm *pt;
            time_t t;
            char date[13];
            t = time(NULL);
            pt = localtime(&t);
            //strftime((top_players+i)->date,14,"%d/%m/%Y\n",pt);
            strftime((top_players+i)->date,14,"%d/%m/%Y \n",pt);
            (top_players+i)->score = score ;

                break;
    }

}
return i;
}
