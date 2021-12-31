#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED
#define color0  {255,0,0,255}
#define color1  {0,255,0,255}
#define color2  {0,0,255,255}
#define color3  {255,255,0,255}
#define color4  {255,0,255,255}
#define color5  {0,255,255,255}
#define color6  {128,128,0,255}
#define color7  {128,0,128,255}
#define color8  {0,128,128,255}
#define color9  {255,128,128,255}
#define color10 {128,0,255,255}
#include <SDL2/SDL.h>

typedef struct {
int x,y,w,h,filled,moved;
SDL_Color color;
}b;
typedef struct
{
    SDL_Color color;
    int x,y,w,h,pos,nfb,d;
    b center_block;
    b blocks[5][3];
    int bw;
} piece;
Uint32 drag_block(b* b, SDL_Event *event);
int get_hor_center(int pw, int ww);
int get_ver_center(int ph, int wh);
void render_piece(piece* p,SDL_Texture *pt,SDL_Renderer *renderer);
void  drag_piece(piece* p, SDL_Event *event);
int drop_piece(piece *p, SDL_Event *event,b* grid, SDL_Renderer* renderer, SDL_Texture* bt);
int change_piece_pos(piece *p,int dx, int dy);
//int animate_piece(piece *p,piece *p2,piece *p3,SDL_Texture *pt,SDL_Texture *pt2,SDL_Texture *pt3,SDL_Texture *bt,SDL_Renderer *renderer,b grid[10][10],int jump, int sum, SDL_Color gc);
int  animate_piece(SDL_Texture *text, SDL_Rect text_rect,SDL_Texture *score_text,SDL_Rect score_rect,piece *p,piece *p2,piece *p3,SDL_Texture *pt,SDL_Texture *pt2,SDL_Texture *pt3,SDL_Texture *bt,SDL_Renderer *renderer,b grid[10][10],int jump, int sum, SDL_Color gc);
void render_grid(b grid[10][10], SDL_Texture *bt , SDL_Renderer *renderer, SDL_Color gc);




#endif // PIECE_H_INCLUDED
