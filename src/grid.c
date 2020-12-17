#include "grid.h"

struct grid
{
    SDL_Renderer* renderer;
    SDL_Rect* viewport;
    struct fabtrimino* active_piece;
    struct square* matrix[GRID_WIDTH][GRID_HEIGHT];
    struct vector active_piece_pos;
};

struct grid* grid_make(SDL_Renderer* renderer, SDL_Rect* viewport)
{
    assert(renderer != NULL);
    assert(viewport != NULL);

    struct grid* grid = calloc(1, sizeof(*grid));
    memset(grid->matrix, 0, GRID_WIDTH*GRID_HEIGHT*sizeof(grid->matrix[0][0]));

    grid->renderer = renderer;
    grid->viewport = viewport;
    grid->active_piece = NULL;

    return grid;
}

void grid_receive(struct grid* grid, struct fabtrimino* fab)
{
    if (grid->active_piece != NULL)
    {
        fab_free(grid->active_piece);
    }
    grid->active_piece = fab;
    grid->active_piece_pos = (struct vector) {.x = 3, .y = 0}; // TODO: adapt to shapes
}

void grid_draw(struct grid* g)
{
    sdl_err(SDL_RenderSetViewport(g->renderer, g->viewport));
    sdl_err(SDL_SetRenderDrawColor(g->renderer, 0x00, 0x00, 0x00, 0xFF));
    SDL_Rect background = {
        .x = 0,
        .y = 0,
        .w = g->viewport->w,
        .h = g->viewport->h
    };
    sdl_err(SDL_RenderFillRect(g->renderer, &background));
    fab_draw(g->active_piece, g->renderer, &g->active_piece_pos);
}