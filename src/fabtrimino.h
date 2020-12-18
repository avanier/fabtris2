#pragma once
#include<stddef.h>
#include<SDL2/SDL.h>
#include "common.h"

enum shape
{
    I, J, L, O, S, T, Z
};

struct fabtrimino* fab_make(enum shape);

void fab_free(struct fabtrimino*);

void fab_draw(struct fabtrimino*, SDL_Renderer*, struct vector*);

void fab_rotate_clockwise(struct fabtrimino*);

void fab_rotate_counter_clockwise(struct fabtrimino*);
