/***************************************
* Joe Zhang                            *
* Mr. Kronberg                         *
* ICS 4U                               *
* Towers of Hanoi                      *
* November 2nd, 2020                   *
****************************************/

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "hanoi.h"
#include "APVECTOR.H"

using namespace std;

int main(int argc, char *argv){

    //initialize allegro
    al_init();

    //declare allegro pointers
    ALLEGRO_DISPLAY *display = nullptr;
    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    ALLEGRO_FONT *font = nullptr;
    ALLEGRO_FONT *font2 = nullptr;
    ALLEGRO_EVENT_QUEUE *event_queue = nullptr;

    //declare variables
    //there are 3 disks by default (it is not hard coded, it can be changed)
    STACK peg[3];
    int numberOfPlates = 3;
    int numberOfMoves = 0;
    int recursiveCounter = 0;

    //initialize variables for the peg number (These are constant)
    //These values just mark the peg number (ie. the first peg is peg 1)
    peg[0].num = 1;
    peg[1].num = 2;
    peg[2].num = 3;

    //install fonts
    installFont(display, font, font2);

    //initialize display
    //program exits with an error if display is not created
    if (initializeDisplay(display) == -1){
        return 1;
    }

    //initialize primatives addons
    //program exits with an error if primatives are not initialized
    if (initializePrimatives(display)== -1){
        return 1;
    }

    //install mouse
    //program exits with an error if the mouse is not installed
    if (installMouse(display) == -1){
        return 1;
    }

    //create event queue
    //program exits with an error if the event queue is not created
    if (createEventQueue(display, event_queue) == -1){
        return 1;
    }

    //register events
    //make sure the display and the mouse are functional
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());

    //Draw title page
    drawTitlePage(font, font2);

    //wait for user to click start
    //exit with no errors if the display is closed
    if (clickStart(event_queue) == 1){
        return 0;
    }

    //Write down instructions
    instructions(font2);

    //wait for user to press the continue button
    //exit with no errors if the display is closed
    if (continueButton(event_queue) == 1){
        return 0;
    }

    //push all the plates into the first stack
    for (int i = numberOfPlates; i > 0; i--){
        peg[0].push(i);
    }

    //draw the initial display with the first stack full and the other stacks empty
    draw(peg, numberOfPlates, numberOfMoves, recursiveCounter);

    //This function makes the buttons work
    //It will only exit if the quit button is clicked
    //Recursive function is called in this function
    buttons(event_queue, numberOfPlates, peg, numberOfMoves, recursiveCounter);

    //free up memory
    al_destroy_display(display);

    //exit with no errors
    return 0;
}
