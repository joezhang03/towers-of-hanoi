#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "hanoi.h"
#include "APVECTOR.H"

using namespace std;

//This is the recursive function
//some arguments are used only in the move or draw functions
void hanoi(int n, int &s, int &d, int &m, int &moves, STACK peg[], int numPlates, int &counter){

    //increment number of recursive calls
    counter++;
    //make the disk move if there is only one disk left in the source pole
    if (n <= 1){
        moveLastPlate(n, s, d, moves, peg, numPlates, counter);
    }
    else{
        //move all disks except for the bottom disk to the middle peg
        //move bottom disk to the peg in the far right
        //move the other plates to the peg in the far right
        hanoi(n-1, s, m, d, moves, peg, numPlates, counter);
        moveLastPlate(n, s, d, moves, peg, numPlates, counter);
        hanoi(n-1, m, d, s, moves, peg, numPlates, counter);
    }
}

//this function moves the plates
void moveLastPlate(int &n, int &s, int &d, int &moves, STACK peg[], int numPlates, int &counter){
    //pop the top of the source stack
    int num = peg[s].pop();
    //push the same number/disk into the destination peg
    peg[d].push(num);
    //count number of moves
    moves++;
    //redraw the pegs each time a disk is moved
    draw(peg, numPlates, moves, counter);
    //wait 0.5 seconds before another move is made
    al_rest(0.5);
    //write down the move of each disk in the console
    cout << "Move plate number " << n << " from column " << peg[s].num << " to column " << peg[d].num << endl;
}
