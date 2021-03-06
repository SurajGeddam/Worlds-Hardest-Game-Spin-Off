#include "main.h"

#include <stdio.h>
#include <stdlib.h>

#include "gba.h"
/* TODO: */
// Include any header files for title screen or exit
// screen images generated by nin10kit. Example for the provided garbage
// image:

#include "images/garbage.h"
#include "images/lost.h"
#include "images/win.h"
#include "images/coin.h"
#include "images/person.h"
#include "images/cake.h"

/* TODO: */
// Add any additional states you need for your applayer. You are not requried to use
// these specific provided states.

Player player = {0, 0, 70, player_size, player_size};
Coin firstCoin = {1, 65, 72, coin_size, coin_size};
Coin middleCoin = {1, 140, 72, coin_size, coin_size};
Coin lastCoin = {1, 215, 72, coin_size, coin_size};
Enemy firstEnemy = {0, 30, 130, enemy_size, enemy_size};
Enemy enemyOnFirstCoin = {0, 60, 30, enemy_size, enemy_size};
Enemy middleEnemy = {0, 97, 130, enemy_size, enemy_size};
Enemy enemyOnMiddleCoin = {0, 135, 30, enemy_size, enemy_size};
Enemy lastEnemy = {0, 172, 130, enemy_size, enemy_size};
Enemy enemyOnLastCoin = {0, 210, 30, enemy_size, enemy_size};

int main(void) {
  /* TODO: */
  // Manipulate REG_DISPCNT here to set Mode 3. //
  REG_DISPCNT = MODE3 | BG2_ENABLE;
  //videoBuffer[1208] = 0x7fff;

  // Save current and previous state of button input.
  u32 previousButtons = BUTTONS;
  u32 currentButtons = BUTTONS;

  // Load initial application state
  enum gbastate state = INIT;

  int coins = 0;
  while (1) {
    currentButtons = BUTTONS; // Load the current state of the buttons

    /* TODO: */
    // Manipulate the state machine below as needed //
    // NOTE: Call waitForVBlank() before you draw

    waitForVBlank();

    switch (state) {
      case INIT:
        drawFullScreenImageDMA(cake);
        drawString(150, 2, "PRESS ENTER TO PLAY", BLUE);
        state = START;
        break;
      case START:
        if (KEY_DOWN(BUTTON_START, currentButtons)) {
          state = PLAY;
        }
        break;
      case PLAY:
        fillScreenDMA(BLACK);

        drawImageDMA(player.row, player.col, player.width, player.height, person);
        if (firstCoin.state) {
          drawImageDMA(firstCoin.row, firstCoin.col, firstCoin.width, firstCoin.height, coin);
        }
        if (middleCoin.state) {
          drawImageDMA(middleCoin.row, middleCoin.col, middleCoin.width, middleCoin.height, coin);
        }
        if (lastCoin.state) {
          drawImageDMA(lastCoin.row, lastCoin.col, lastCoin.width, lastCoin.height, coin);
        }

        drawImageDMA(firstEnemy.row, firstEnemy.col, firstEnemy.width, firstEnemy.height, garbage);
        drawImageDMA(middleEnemy.row, middleEnemy.col, middleEnemy.width, middleEnemy.height, garbage);
        drawImageDMA(lastEnemy.row, lastEnemy.col, lastEnemy.width, lastEnemy.height, garbage);
        drawImageDMA(enemyOnFirstCoin.row, enemyOnFirstCoin.col, enemyOnFirstCoin.width, enemyOnFirstCoin.height, garbage);
        drawImageDMA(enemyOnMiddleCoin.row, enemyOnMiddleCoin.col, enemyOnMiddleCoin.width, enemyOnMiddleCoin.height, garbage);
        drawImageDMA(enemyOnLastCoin.row, enemyOnLastCoin.col, enemyOnLastCoin.width, enemyOnLastCoin.height, garbage);

        drawString(150, 2, "Coins:", WHITE);
        drawChar(150, 40, coins + 48, WHITE);

        if (firstEnemy.row == 0) {
          firstEnemy.state = 0;
        } else if (firstEnemy.row == 130) {
          firstEnemy.state = 1;
        } 
        
        if (firstEnemy.state) {
          firstEnemy.row -= enemy_Speed;
        } else if (!firstEnemy.state) {
          firstEnemy.row += enemy_Speed;
        }

        if (middleEnemy.row == 0) {
          middleEnemy.state = 0;
        } else if (middleEnemy.row == 130) {
          middleEnemy.state = 1;
        } 
        
        if (middleEnemy.state) {
          middleEnemy.row -= enemy_Speed;
        } else if (!middleEnemy.state) {
          middleEnemy.row += enemy_Speed;
        }

        if (lastEnemy.row == 0) {
          lastEnemy.state = 0;
        } else if (lastEnemy.row == 130) {
          lastEnemy.state = 1;
        } 
        
        if (lastEnemy.state) {
          lastEnemy.row -= enemy_Speed;
        } else if (!lastEnemy.state) {
          lastEnemy.row += enemy_Speed;
        }

        if (enemyOnFirstCoin.row == 30) {
          enemyOnFirstCoin.state = 0;
        } else if (enemyOnFirstCoin.row == 130) {
          enemyOnFirstCoin.state = 1;
        } 
        
        if (enemyOnFirstCoin.state) {
          enemyOnFirstCoin.row -= enemy_Speed;
        } else if (!enemyOnFirstCoin.state) {
          enemyOnFirstCoin.row += enemy_Speed;
        }

        if (enemyOnMiddleCoin.row == 30) {
          enemyOnMiddleCoin.state = 0;
        } else if (enemyOnMiddleCoin.row == 130) {
          enemyOnMiddleCoin.state = 1;
        } 
        
        if (enemyOnMiddleCoin.state) {
          enemyOnMiddleCoin.row -= enemy_Speed;
        } else if (!enemyOnMiddleCoin.state) {
          enemyOnMiddleCoin.row += enemy_Speed;
        }

        if (enemyOnLastCoin.row == 30) {
          enemyOnLastCoin.state = 0;
        } else if (enemyOnLastCoin.row == 130) {
          enemyOnLastCoin.state = 1;
        } 
        
        if (enemyOnLastCoin.state) {
          enemyOnLastCoin.row -= enemy_Speed;
        } else if (!enemyOnLastCoin.state) {
          enemyOnLastCoin.row += enemy_Speed;
        }

        if (KEY_DOWN(BUTTON_DOWN, BUTTONS)) {
          if (player.row < 130) {
            player.row++;
          }
        }
        if (KEY_DOWN(BUTTON_UP, BUTTONS)) {
          if (player.row > 0) {
            player.row--;
          }
        }
        if (KEY_DOWN(BUTTON_LEFT, BUTTONS)) {
          if (player.col > 0) {
            player.col--;
          }
        }
        if (KEY_DOWN(BUTTON_RIGHT, BUTTONS)) {
          if (player.col < 230) {
            player.col++;
          }
        }

        if (KEY_DOWN(BUTTON_SELECT, BUTTONS)) {
          firstCoin.state = 1;
          middleCoin.state = 1;
          lastCoin.state = 1;
          state = INIT;
          player.col = 0;
          player.row = 70;
          coins = 0;
        }

        if ((collision(firstEnemy.row, firstEnemy.col, firstEnemy.width, firstEnemy.height, player.row, player.col, player.width, player.height)) || 
            (collision(middleEnemy.row, middleEnemy.col, middleEnemy.width, middleEnemy.height, player.row, player.col, player.width, player.height)) ||
              (collision(lastEnemy.row, lastEnemy.col, lastEnemy.width, lastEnemy.height, player.row, player.col, player.width, player.height)) || 
                (collision(enemyOnFirstCoin.row, enemyOnFirstCoin.col, enemyOnFirstCoin.width, enemyOnFirstCoin.height, player.row, player.col, player.width, player.height)) || 
                  (collision(enemyOnMiddleCoin.row, enemyOnMiddleCoin.col, enemyOnMiddleCoin.width, enemyOnMiddleCoin.height, player.row, player.col, player.width, player.height)) ||  
                    (collision(enemyOnLastCoin.row, enemyOnLastCoin.col, enemyOnLastCoin.width, enemyOnLastCoin.height, player.row, player.col, player.width, player.height))) {
                      firstCoin.state = 1;
                      middleCoin.state = 1;
                      lastCoin.state = 1;
                      state = LOST;
                      player.col = 0;
                      player.row = 70;
                      coins = 0;
        }

        if (firstCoin.state && (collision(firstCoin.row, firstCoin.col, firstCoin.width, firstCoin.height, player.row, player.col, player.width, player.height))) {
          coins++;
          firstCoin.state = 0;
        }

        if (middleCoin.state && (collision(middleCoin.row, middleCoin.col, middleCoin.width, middleCoin.height, player.row, player.col, player.width, player.height))) {
          coins++;
          middleCoin.state = 0;
        }

        if (lastCoin.state && (collision(lastCoin.row, lastCoin.col, lastCoin.width, lastCoin.height, player.row, player.col, player.width, player.height))) {
          coins++;
          lastCoin.state = 0;
        }

        if (coins == 3) {
          state = WIN;
          }


        break;

      case WIN:
        drawFullScreenImageDMA(win);
        drawString(150, 2, "PRESS BACKSPACE TO PLAY AGAIN", BLUE);
        if (KEY_DOWN(BUTTON_SELECT, BUTTONS)) {
          firstCoin.state = 1;
          middleCoin.state = 1;
          lastCoin.state = 1;
          state = INIT;
          player.col = 0;
          player.row = 70;
          coins = 0;
        }
        break;

      case LOST:
        drawFullScreenImageDMA(lost);
        drawString(150, 2, "PRESS BACKSPACE TO PLAY AGAIN", BLUE);
        if (KEY_DOWN(BUTTON_SELECT, BUTTONS)) {
          firstCoin.state = 1;
          middleCoin.state = 1;
          lastCoin.state = 1;
          state = INIT;
          player.col = 0;
          player.row = 70;
          coins = 0;
        }
        break;
    }

    previousButtons = currentButtons; // Store the current state of the buttons
  }

  UNUSED(previousButtons); // You can remove this once previousButtons is used

  return 0;
}
