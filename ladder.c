#include "board.h"
#include "snake.h"
#include "tiles.h"
#include "ladder.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ladder {
    int Start;
    int End;
};


Ladder *new_ladder(int start,int end)
{
    Ladder *new_ladder = malloc(sizeof(*new_ladder));
    assert(new_ladder!=NULL);
    new_ladder->Start = start;
    new_ladder->End = end;
    return new_ladder;

}
