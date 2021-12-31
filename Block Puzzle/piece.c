#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "piece.h"

Uint32 drag_block(b* b, SDL_Event *event)
{
    int mx,my;
    SDL_GetMouseState(&mx,&my);
    if(mx>(b->x) && (mx<(b->x+(30))) && (my>(b->y)) && (my<(b->y+(30)))&& (event->button.button==SDL_BUTTON_LEFT))
    {
        b->x = mx-(30/2);
        b->y = my-(30/2);
        SDL_GetMouseState(&mx,&my);
    }
    return 0;
}

int get_hor_center(int pw, int ww)
{
    return (ww-pw)/2;
}

int get_ver_center(int ph, int wh)
{
    return (wh-ph)/2;
}

void render_piece(piece* p,SDL_Texture *pt,SDL_Renderer *renderer)
{
    for (int i=0; i<5; i++)
    {
        int k=0;
        for(int j=0; j<3; j++)
        {
            if (p->blocks[i][j].filled==1)
            {
                SDL_SetTextureColorMod(pt,p->color.r,p->color.g,p->color.b);
                SDL_Rect bri = {p->blocks[i][j].x,p->blocks[i][j].y,30,30};
                SDL_RenderCopy(renderer,pt,NULL,&bri);
            }
        }
        k +=30;
    }
}

void drag_piece(piece* p, SDL_Event *event)

{
    int targeted = 0;
    int dx=0;
    int dy=0;
    int i=0;
    int j=0;
    int mx,my;
    int px;
    int py;
    SDL_GetMouseState(&mx,&my);
    for(i=0; i<5; i++)
    {
        for(j=0; j<3; j++)
        {
            if( (mx>(p->blocks[i][j].x)) && (mx<(p->blocks[i][j].x)+(30)) && (my>(p->blocks[i][j].y)) && (my<(p->blocks[i][j].y)+(30))&& (event->button.button==SDL_BUTTON_LEFT))
            {

                px = p->blocks[i][j].x;
                py = p->blocks[i][j].y;
                p->blocks[i][j].x = mx-(30/2);
                p->blocks[i][j].y = my-(30/2);
                dx = p->blocks[i][j].x - px;
                dy = p->blocks[i][j].y - py;
                p->blocks[i][j].moved = 1;


            }

        }
    }


    for(i=0; i<5; i++)
    {
        for(j=0; j<3; j++)
        {
            if(p->blocks[i][j].moved != 1)
            {
                p->blocks[i][j].x += dx;
                p->blocks[i][j].y += dy;

            }
            p->blocks[i][j].moved = 0;
        }
    }

}




/*new drop piece*/

int drop_piece(piece* p, SDL_Event *event,b* grid, SDL_Renderer* renderer, SDL_Texture* bt)
{
    int cpt=0;
    int dropped=0;
    int m=0;
    for(int i=0; i<10; i++)
    {
        for (int  j=0; j<10; j++)
        {
            for(int  k=0; k<5; k++)
            {
                for(int l=0; l<3; l++)
                {
                    if(    ( (p->blocks[k][l].x) >= (((grid+i+j+m)->x)-10)) &&
                            ((p->blocks[k][l].x) <= (((grid+i+j+m)->x) + 10))
                            && ( (p->blocks[k][l].y) >= (((grid+i+j+m)->y)-10) ) && ( (p->blocks[k][l].y) <= (((grid+i+j+m)->y)+10) )
                            && ( ((grid+i+j+m)->filled) == 0) && (event->type == SDL_MOUSEBUTTONUP) )
                    {
                        cpt++;
                    }
                }
            }
        }
        m +=9;
    }
    m=0;
    if(cpt==p->nfb)
    {
        for(int i=0; i<10; i++)
        {
            for (int  j=0; j<10; j++)
            {
                for(int  k=0; k<5; k++)
                {
                    for(int l=0; l<3; l++)
                    {
                        if(    ( (p->blocks[k][l].x) >= (((grid+i+j+m)->x)-10)) &&
                                ((p->blocks[k][l].x) <= (((grid+i+j+m)->x) + 10))
                                && ( (p->blocks[k][l].y) >= (((grid+i+j+m)->y)-10) ) && ( (p->blocks[k][l].y) <= (((grid+i+j+m)->y)+10) )
                                && ( ((grid+i+j+m)->filled) == 0) && (event->type == SDL_MOUSEBUTTONUP) )
                        {
                            (grid+i+j+m)->filled = 1;
                            dropped = 1;
                            (grid+i+j+m)->color = p->color;
                        }
                    }
                }
            }
            m +=9;
        }
    }
    if(dropped==1)
    {

        for(int k=0; k<5; k++)
        {
            for(int l=0; l<3; l++)
            {
                p->blocks[k][l].filled=0;
            }
        }

    }

    return dropped;
//end drop
}


int change_piece_pos(piece *p,int dx, int dy){
    for (int i=0; i<5; i++)
    {
        for(int j=0; j<3; j++)
        {
            p->blocks[i][j].x  = p->blocks[i][j].x+ dx;
            p->blocks[i][j].y  = p->blocks[i][j].y+ dy;

        }
    }
return 0;
}

int  animate_piece(SDL_Texture *text, SDL_Rect text_rect,SDL_Texture *score_text,SDL_Rect score_rect,piece *p,piece *p2,piece *p3,SDL_Texture *pt,SDL_Texture *pt2,SDL_Texture *pt3,SDL_Texture *bt,SDL_Renderer *renderer,b grid[10][10],int jump, int sum, SDL_Color gc){

while(p->blocks[0][0].y>grid[jump][sum].y){
   for (int i=0; i<5; i++)
    {
        for(int j=0; j<3; j++)
        {

            //p.blocks[i][j].x  = p.blocks[i][j].x+ dx;
            p->blocks[i][j].y  = p->blocks[i][j].y-5;

        }
    }


    render_grid(grid, bt, renderer, gc);
    render_piece(p,pt,renderer);
    render_piece(p2,pt2,renderer);
    render_piece(p3,pt3,renderer);
    SDL_RenderCopy(renderer,score_text,NULL,&score_rect);
    SDL_RenderCopy(renderer,text,NULL,&text_rect);
    SDL_RenderPresent(renderer);
}

while(p->blocks[0][0].x>grid[jump][sum].x){
   for (int i=0; i<5; i++)
    {
        for(int j=0; j<3; j++)
        {
            p->blocks[i][j].x  = p->blocks[i][j].x-5;

        }
    }
    render_grid(grid, bt, renderer, gc);
    render_piece(p,pt,renderer);
    render_piece(p2,pt2,renderer);
    render_piece(p3,pt3,renderer);
    SDL_RenderCopy(renderer,score_text,NULL,&score_rect);
    SDL_RenderCopy(renderer,text,NULL,&text_rect);
    SDL_RenderPresent(renderer);
}

while(p->blocks[0][0].x<grid[jump][sum].x){
   for (int i=0; i<5; i++)
    {
        for(int j=0; j<3; j++)
        {
            p->blocks[i][j].x  = p->blocks[i][j].x+5;

        }
    }
    render_grid(grid, bt, renderer, gc);
    render_piece(p,pt,renderer);
    render_piece(p2,pt2,renderer);
    render_piece(p3,pt3,renderer);
    SDL_RenderCopy(renderer,score_text,NULL,&score_rect);
    SDL_RenderCopy(renderer,text,NULL,&text_rect);
    SDL_RenderPresent(renderer);
}
}

void render_grid(b grid[10][10], SDL_Texture *bt , SDL_Renderer *renderer, SDL_Color gc){
        SDL_SetRenderDrawColor(renderer,200,255,255,255);
        SDL_RenderClear(renderer);
        for (int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                if(grid[i][j].filled==0)
                {
                    SDL_SetTextureColorMod(bt,gc.r,gc.g,gc.b);
                    SDL_Rect bri = {grid[i][j].x,grid[i][j].y,30,30};
                    SDL_RenderCopy(renderer,bt,NULL,&bri);
                }
                else{
                    SDL_SetTextureColorMod(bt,grid[i][j].color.r,grid[i][j].color.g,grid[i][j].color.b);
                     SDL_Rect bri = {grid[i][j].x,grid[i][j].y,30,30};
                    SDL_RenderCopy(renderer,bt,NULL,&bri);

                }


            }
        }






}







