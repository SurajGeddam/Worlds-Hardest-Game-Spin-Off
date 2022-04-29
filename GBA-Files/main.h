#ifndef MAIN_H
#define MAIN_H

#include "gba.h"

// TODO: Create any necessary structs

/*
* For example, for a Snake game, one could be:
*
* struct snake {
*   int heading;
*   int length;
*   int row;
*   int col;
* };
*
* Example of a struct to hold state machine data:
*
* struct state {
*   int currentState;
*   int nextState;
* };
*
*/

#define player_size 10
#define enemy_size 15
#define coin_size 5
#define player_Speed 1
#define enemy_Speed 2

enum gbastate {
  INIT,
  START,
  PLAY,
  WIN,
  LOST,
};

typedef struct {
    int state;
    int col;
    int row;
    int width;
    int height;
} Player;

typedef struct {
    int state;
    int col;
    int row;
    int width;
    int height;
} Coin;


typedef struct {
    int state;
    int col;
    int row;
    int width;
    int height;
} Enemy;


#endif