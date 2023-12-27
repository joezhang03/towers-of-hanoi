#include <iostream>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "hanoi.h"
#include "APVECTOR.H"

using namespace std;

//This function makes the buttons functional and the game playable by the user
int buttons (ALLEGRO_EVENT_QUEUE *event_queue, int &n, STACK peg[], int &moves, int &counter){

    //declare variables
    int start = 0;
    int middle = 1;
    int destination = 2;
    bool select = false;
    int startP;
    int destP;
    bool correctRange = false;
    apvector<int> sList;

    //exit only if user clicks the quit button or if the display is closed
    while (!select){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        //exit with no errors if display is closed
        if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE){
            select = true;
        }
        //call the recursive algorithm if the solve button is clicked
        else if(ev.mouse.x >= SCREEN_WIDTH-200 && ev.mouse.y >= 100 && ev.mouse.x <= SCREEN_WIDTH-50 &&
                ev.mouse.y <= 200 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            //set number of moves to 0
            moves = 0;
            //set recursive counter to 0
            counter = 0;
            //pop everything from each stack
            for (int i = 0; i < NUM_PEGS; i++){
                sList = peg[i].readData();
                if (sList.length()  > 0){
                    for (int j = 0; j < sList.length() - 1; j++)
                        peg[i].pop();
                }
            }
            //push everything into the first stack
            //redraws the pegs and the disks
            for (int i = n; i > 0; i--){
                peg[0].push(i);
                draw(peg, n, moves, counter);
            }
            //clear the console screen
            system("CLS");
            //call recursive function
            hanoi(n, start, destination, middle, moves, peg, n, counter);
            //print number of moves in console
            cout << moves << " moves" << endl;
            cout << counter << " recursive calls" << endl;
        }
        //moves all the disks back to the first stack if reset button is clicked
        else if (ev.mouse.x >= SCREEN_WIDTH - 200 && ev.mouse.y >= 300 && ev.mouse.x <= SCREEN_WIDTH - 50 &&
                 ev.mouse.y <= 400 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            //set number of moves to 0
            moves = 0;
            //set recursive counter to 0
            counter = 0;
            //pop everything from every stack
            for (int i = 0; i < NUM_PEGS; i++){
                sList = peg[i].readData();
                if (sList.length()  > 0){
                    for (int j = 0; j < sList.length() - 1; j++)
                        peg[i].pop();
                }
            }
            //push everything into the first stack
            //redraws the pegs and the disks
            for (int i = n; i > 0; i--){
                peg[0].push(i);
                draw(peg, n, moves, counter);
            }
            //clear console screen
            system("CLS");
        }
        //exit with no errors if the quit button is clicked
        else if (ev.mouse.x >= SCREEN_WIDTH - 200 && ev.mouse.y >= 500 && ev.mouse.x <= SCREEN_WIDTH - 50 &&
                 ev.mouse.y <= 600 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            select = true;
        }
        //increase the number of disks by 1 if the up button is clicked
        //it also moves all the disks back to the first stack
        else if(ev.mouse.x >= 50 && ev.mouse.y >= 100 && ev.mouse.x <= 135 && ev.mouse.y <= 200 &&
           ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && n < 7){

            //pop everything from every stack
            for (int i = 0; i < NUM_PEGS; i++){
                sList = peg[i].readData();
                if (sList.length()  > 0){
                    for (int j = 0; j < sList.length() - 1; j++)
                        peg[i].pop();
                }
            }
            //push everything into first stack
            for (int i = n; i > 0; i--){
                peg[0].push(i);
                draw(peg, n, moves, counter);
            }

            //pop everything from first stack
            for(int i = 0; i < n; i++){
                peg[0].pop();
            }
            //increment the number of disks
            n++;
            //push everything back to the first stack with updated number of disks
            for (int i = n; i > 0; i--){
                peg[0].push(i);
            }
            //redraws the pegs and the disks
            draw(peg, n, moves, counter);
        }

        //decrease the number of disks by 1 if the down button is clicked
        //also moves everything back to the first stack
        else if(ev.mouse.x >= 250 && ev.mouse.y >= 100 && ev.mouse.x <= 335 && ev.mouse.y <= 200
                && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && n > 3){
            //pop everything from each stack
            for (int i = 0; i < NUM_PEGS; i++){
                sList = peg[i].readData();
                if (sList.length()  > 0){
                    for (int j = 0; j < sList.length() - 1; j++)
                        peg[i].pop();
                }
            }
            //push everything into the first stack
            for (int i = n; i > 0; i--){
                peg[0].push(i);
                draw(peg, n, moves, counter);
            }
            //pop everything from the first stack
            for(int i = 0; i < n; i++){
                peg[0].pop();
            }
            //decrease the number of disks by 1
            n--;
            //push everything back into the first stack with updated number of disks
            for (int i = n; i > 0; i--){
                peg[0].push(i);
            }
            //redraws the pegs and the disks
            draw(peg, n, moves, counter);
        }
        /*************THESE ARE ALL THE CODE THAT MAKES THE GAME PLAYABLE BY THE USER MANUALLY**********************************/
        //check if the first/left peg is clicked
        //make the first peg the source peg if it is clicked
        else if (ev.mouse.x >= 1.0*SCREEN_WIDTH/4 - 100 && ev.mouse.y >= 1.0*SCREEN_HEIGHT/4 && ev.mouse.x <= 1.0*SCREEN_WIDTH/4 + 110 && ev.mouse.y <= SCREEN_HEIGHT
                  && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
                    startP = 0;
                    correctRange = true;
        }
        //check if the second/middle peg is clicked
        //make the second peg the source peg if it is clicked
        else if (ev.mouse.x >= 1.0*SCREEN_WIDTH/2 - 100 && ev.mouse.y >= 1.0*SCREEN_HEIGHT/4 && ev.mouse.x <= 1.0*SCREEN_WIDTH/2 + 110 && ev.mouse.y <= SCREEN_HEIGHT &&
                 ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
                    startP = 1;
                    correctRange = true;
        }
        //check if the third peg/right is clicked
        //make the third peg the source peg if it is clicked
        else if (ev.mouse.x >= 3.0*SCREEN_WIDTH/4 - 100 && ev.mouse.y >= 1.0*SCREEN_HEIGHT/4 && ev.mouse.x <= 3.0*SCREEN_WIDTH/4 + 110 && ev.mouse.y <= SCREEN_HEIGHT &&
                 ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
                    startP = 2;
                    correctRange = true;
        }
        //check if the mouse key is released at the first/left peg
        //move the top disk from the source peg clicked to the left peg
        //also increments the number of moves
        else if (ev.mouse.x >= 1.0*SCREEN_WIDTH/4 - 100 && ev.mouse.y >= 1.0*SCREEN_HEIGHT/4 && ev.mouse.x <= 1.0*SCREEN_WIDTH/4 + 110 && ev.mouse.y <= SCREEN_HEIGHT
                  && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    destP = 0;
                    if (startP != destP && correctRange){
                        if (peg[startP].getStackTop() < peg[destP].getStackTop()){
                            peg[destP].push(peg[startP].pop());
                            moves++;
                        }
                        draw(peg, n, moves, counter);
                    }
                    correctRange = false;
        }
        //check if the mouse key is released at the second/middle peg
        //move the top disk from the source peg clicked to the middle peg
        //also increments the number of moves
        else if (ev.mouse.x >= 1.0*SCREEN_WIDTH/2 - 100 && ev.mouse.y >= 1.0*SCREEN_HEIGHT/4 && ev.mouse.x <= 1.0*SCREEN_WIDTH/2 + 110 && ev.mouse.y <= SCREEN_HEIGHT &&
                 ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    destP = 1;
                    if (startP!=destP && correctRange){
                        if (peg[startP].getStackTop() < peg[destP].getStackTop()){
                            peg[destP].push(peg[startP].pop());
                            moves++;
                        }
                    draw(peg, n, moves, counter);
                    }
                    correctRange = false;

        }
        //check if the mouse key is released at the third/right peg
        //move the top disk from the source peg clicked to the right peg
        //also increments the number of moves
        else if (ev.mouse.x >= 3.0*SCREEN_WIDTH/4 - 100 && ev.mouse.y >= 1.0*SCREEN_HEIGHT/4 && ev.mouse.x <= 3.0*SCREEN_WIDTH/4 + 110 && ev.mouse.y <= SCREEN_HEIGHT &&
                 ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            destP = 2;
            if (startP!=destP && correctRange){
                if (peg[startP].getStackTop() < peg[destP].getStackTop()){
                    peg[destP].push(peg[startP].pop());
                    moves++;
                }
                draw(peg, n, moves, counter);
            }
            correctRange = false;
        }
    }
    return 0;
}

