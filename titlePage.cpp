#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "hanoi.h"
#include "APVECTOR.H"

//this function draws the title/menu page
void drawTitlePage(ALLEGRO_FONT *font, ALLEGRO_FONT *font2){
    //clear background to a pale green colour
    al_clear_to_color(PALE_GREEN);

    //write down title of the game
    al_draw_text(font, BLACK, (SCREEN_WIDTH/2), (SCREEN_HEIGHT/4), ALLEGRO_ALIGN_CENTER, "TOWERS OF HANOI");

    //tells user to click start button
    al_draw_text(font2, BLACK, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, ALLEGRO_ALIGN_CENTER, "Click Start to begin");

    //draw start button
    al_draw_filled_rounded_rectangle(1.0*SCREEN_WIDTH/2 - 100, 3.0*SCREEN_HEIGHT/4 - 50, 1.0*SCREEN_WIDTH/2 + 100, 3.0*SCREEN_HEIGHT/4 + 50, 20, 20, SKY_BLUE);
    al_draw_rounded_rectangle(1.0*SCREEN_WIDTH/2 - 100, 3.0*SCREEN_HEIGHT/4 - 50, 1.0*SCREEN_WIDTH/2 + 100, 3.0*SCREEN_HEIGHT/4 + 50, 20, 20, WHITE, 3);
    al_draw_text(font2, BLACK, (SCREEN_WIDTH/2), (3.0*SCREEN_HEIGHT/4-20), ALLEGRO_ALIGN_CENTER, "START");

    //write down author's name
    al_draw_text(font2, BLACK, 0, SCREEN_HEIGHT - 50, ALLEGRO_ALIGN_LEFT, "By: Joe Zhang");

    //show display
    al_flip_display();
}

int clickStart(ALLEGRO_EVENT_QUEUE *event_queue){

    //declare variables
    bool select = false;

    //wait until user clicks start button
    //program exits with no errors if the display is closed
    while (!select){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            return 1;
        }
        else if (ev.mouse.x >= (1.0*SCREEN_WIDTH/2 - 100) && ev.mouse.y >= (3.0*SCREEN_HEIGHT/4 - 50)
            && ev.mouse.x <= (1.0*SCREEN_WIDTH/2 + 100) && ev.mouse.y <= (3.0*SCREEN_WIDTH/4 + 50) &&
            ev.type==ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            select = true;
        }
    }
    return 0;
}

//This function writes down the instructions for the user to follow
//It makes the user understand how to play the game and how to play the recursive animation
void instructions(ALLEGRO_FONT *font){
    al_clear_to_color(PALE_GREEN);
    al_draw_text(font, BLACK, 0, 50, ALLEGRO_ALIGN_LEFT, "To adjust the number of disks: Click blue arrow buttons");
    al_draw_text(font, BLACK, 0, 150, ALLEGRO_ALIGN_LEFT, "To play animation: Click green SOLVE button");
    al_draw_text(font, BLACK, 0, 250, ALLEGRO_ALIGN_LEFT, "To Play manually: Drag and drop");
    al_draw_text(font, BLACK, 0, 350, ALLEGRO_ALIGN_LEFT, "To reset disks to first peg: Click the yellow RESET button");
    al_draw_text(font, BLACK, 0, 450, ALLEGRO_ALIGN_LEFT, "To exit game: Click red QUIT button");
    al_draw_text(font, BLACK, 0, 550, ALLEGRO_ALIGN_LEFT, "The disk will not move with the mouse, hold the mouse button down when you click on");
    al_draw_text(font, BLACK, 0, 600, ALLEGRO_ALIGN_LEFT, "the disk at the source peg and release it at the destination peg to make a move");

    //draw continue button
    al_draw_filled_rounded_rectangle(1.0*SCREEN_WIDTH/2 - 100, 700, 1.0*SCREEN_WIDTH/2 + 100, 750, 20, 20, SKY_BLUE);
    al_draw_rounded_rectangle(1.0*SCREEN_WIDTH/2 - 100, 700, 1.0*SCREEN_WIDTH/2 + 100, 750, 20, 20, WHITE, 5);
    al_draw_text(font, BLACK, 1.0*SCREEN_WIDTH/2, 700, ALLEGRO_ALIGN_CENTER, "Continue");
    al_flip_display();
}

//This function waits until the user clicks the continue button
int continueButton(ALLEGRO_EVENT_QUEUE *event_queue){

    //declare variables
    bool select = false;

    //wait until user hits the continue button
    //program exits with no errors if the display is closed
    while (!select){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            return 1;
        }
        else if (ev.mouse.x >= 1.0*SCREEN_WIDTH/2 - 100 && ev.mouse.y >= 700 && ev.mouse.x <= 1.0*SCREEN_WIDTH/2 + 100 &&
                 ev.mouse.y <= 750 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            select = true;
        }
    }
    return 0;
}
