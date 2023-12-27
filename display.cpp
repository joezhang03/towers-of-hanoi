#include <iostream>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "hanoi.h"
#include "APVECTOR.H"

using namespace std;

//This function draws the pegs and the disks
void draw(STACK peg[], int n, int &moves, int &counter){

    //add a font for displaying text
    ALLEGRO_FONT *font;
    font = al_load_ttf_font("Lemon_Juice.ttf", 36, 0);

    //declare variables
    POINT center [3];
    int xMax = 100;
    int yMax = SCREEN_HEIGHT - SCREEN_HEIGHT/4;
    int xMin = 50;
    int yMin = SCREEN_HEIGHT;
    int xStep = (xMax-xMin)/(n-1);
    int yStep = (yMax-yMin)/(n-1);
    const int PLATE_HEIGHT = 50;
    apvector<int> v(100);
    POINT up;
    POINT down;
    char printString[200];

    //Set a maximum height for each disk
    if (yStep > PLATE_HEIGHT){
        yStep = PLATE_HEIGHT;
    }

    //clear the display to beige colour
    al_clear_to_color(BEIGE);

    //draw the pegs for the towers
    al_draw_filled_rectangle(1.0*SCREEN_WIDTH/4, 1.0*SCREEN_HEIGHT/4, 1.0*SCREEN_WIDTH/4 + 10, 1.0*SCREEN_HEIGHT/4 + (SCREEN_HEIGHT-SCREEN_HEIGHT/4), BROWN);
    al_draw_filled_rectangle(1.0*SCREEN_WIDTH/2, 1.0*SCREEN_HEIGHT/4, 1.0*SCREEN_WIDTH/2 + 10, 1.0*SCREEN_HEIGHT/4 + (SCREEN_HEIGHT-SCREEN_HEIGHT/4), BROWN);
    al_draw_filled_rectangle(3.0*SCREEN_WIDTH/4, 1.0*SCREEN_HEIGHT/4, 3.0*SCREEN_WIDTH/4 + 10, 1.0*SCREEN_HEIGHT/4 + (SCREEN_HEIGHT-SCREEN_HEIGHT/4), BROWN);
    //draw the solve button
    al_draw_filled_rectangle(SCREEN_WIDTH - 200, 100, SCREEN_WIDTH - 50, 200, GREEN);
    al_draw_rectangle(SCREEN_WIDTH - 200, 100, SCREEN_WIDTH - 50, 200, BLACK, 3);
    al_draw_text(font, BLACK, SCREEN_WIDTH-125, 125, ALLEGRO_ALIGN_CENTER, "SOLVE");
    //draw the reset button
    al_draw_filled_rectangle(SCREEN_WIDTH - 200, 300, SCREEN_WIDTH - 50, 400, YELLOW);
    al_draw_rectangle(SCREEN_WIDTH - 200, 300, SCREEN_WIDTH - 50, 400, BLACK, 3);
    al_draw_text(font, BLACK, SCREEN_WIDTH - 125, 325, ALLEGRO_ALIGN_CENTER, "RESET");
    //draw quit button
    al_draw_filled_rectangle(SCREEN_WIDTH - 200, 500, SCREEN_WIDTH - 50, 600, RED);
    al_draw_rectangle(SCREEN_WIDTH - 200, 500, SCREEN_WIDTH - 50, 600, BLACK, 3);
    al_draw_text(font, BLACK, SCREEN_WIDTH - 125, 525, ALLEGRO_ALIGN_CENTER, "QUIT");
    //draw the number of rings selector
    al_draw_text(font, BLACK, 50, 30, ALLEGRO_ALIGN_LEFT, "Number of Rings (3-7)");
    al_draw_filled_rectangle(135, 100, 250, 200, WHITE);
    al_draw_filled_rectangle(50, 100, 135, 200, BLUE);
    al_draw_rectangle(50, 100, 135, 200, BLACK, 3);
    al_draw_filled_triangle(93, 95, 55, 195, 130, 195, BLACK);
    al_draw_filled_rectangle(250, 100, 335, 200, BLUE);
    al_draw_rectangle(250, 100 ,335, 200, BLACK, 3);
    al_draw_filled_triangle(255, 105, 330, 105, 293, 195, BLACK);
    sprintf(printString, "%d", n);
    al_draw_text(font, BLACK, 160, 100, ALLEGRO_ALIGN_CENTER, printString);
    //draw the number of moves
    sprintf(printString, "%d", moves);
    al_draw_text(font, BLACK, 600, 30, ALLEGRO_ALIGN_LEFT, "Moves: ");
    al_draw_text(font, BLACK, 750, 30, ALLEGRO_ALIGN_LEFT, printString);
    //draw the number of recursive calls
    sprintf(printString, "%d", counter);
    al_draw_text(font, BLACK, 600, 60, ALLEGRO_ALIGN_LEFT, "Recursive Calls: ");
    al_draw_text(font, BLACK, 800, 60, ALLEGRO_ALIGN_LEFT, printString);

    //calculate center coordinates of each peg
    center[0].x = (2.0*SCREEN_WIDTH/4 + 10)/2;
    center[0].y = SCREEN_HEIGHT;
    center[1].x = (2.0*SCREEN_WIDTH/2 + 10)/2;
    center[1].y = SCREEN_HEIGHT;
    center[2].x = (6.0*SCREEN_WIDTH/4 + 10)/2;
    center[2].y = SCREEN_HEIGHT;

    //draw plates based on the stack numbers
    for (int i = 0; i < NUM_PEGS; i++){
        //store the stack values into an ap vector
        v = peg[i].readData();
        for (int j = 0; j <v.length()-1; j++){
            //calculate the coordinates of each disk
            up.x = center[i].x - (xMin + (v[j] - 1)*xStep);
            up.y = center[i].y + (v.length()-1 - j)*yStep;
            down.x = center[i].x + xMin + (v[j] - 1)*xStep;
            down.y = center[i].y + (v.length()-1 - j - 1) * yStep;
            //draw the disks
            al_draw_filled_rounded_rectangle(up.x, up.y, down.x, down.y, 10, 10, TURQUOIS);
            al_draw_rounded_rectangle(up.x, up.y, down.x, down.y, 10, 10, BLACK, 5);
            al_flip_display();
        }
    }
}
