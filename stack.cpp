#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "hanoi.h"
#include "APVECTOR.H"

using namespace std;

//class constructor
STACK::STACK(){
    head = NULL;
    stackList.resize(100);
}

//push function
void STACK::push(int n){
    NODE *newNode = new NODE;
    newNode->num = n;
    newNode-> next = head;
    head = newNode;
}

//pop function
int STACK::pop(){
    if(isEmpty()){
        return 0;
    }
    int n;
    NODE *temp = head;
    n = temp->num;
    head = temp -> next;
    delete temp;
    return n;
}

//public getter method that returns the values in the stack
apvector<int> STACK::readData(){
    NODE *node = head;
    //int i = 1;
    int i = 0;
    while (node != NULL){
        stackList[i] = node->num;
        node = node->next;
        i++;
    }
    stackList.resize(i+1);
    return stackList;
}

//returns the stack's top number
int STACK::getStackTop(){

    if (!isEmpty()){
        return head->num;
    }
    return 1000;
}

//checks if the stack is empty
bool STACK::isEmpty(){
    if (head == NULL){
        return true;
    }
    return false;
}
