#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "hanoi.h"
#include "APVECTOR.H"

//This function initializes display
int initializeDisplay(ALLEGRO_DISPLAY *display){
    //exit with an error if something is wrong with the display
    if (!display){
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize display", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    //set the window title
    al_set_window_title(display, "Towers of Hanoi");
    return 0;
}

int initializePrimatives(ALLEGRO_DISPLAY *display){
    // Initialize primative add on
    //exit with an error if the primatives are not added
 	if (!al_init_primitives_addon()) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize primatives addon!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}
	return 0;
}

//This function installs the fonts
int installFont(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *&font, ALLEGRO_FONT *&font2){

    //initialize font
    al_init_font_addon();
    al_init_ttf_addon();

    //add fonts
    font = al_load_ttf_font("FunSized.ttf", 72, 0);
    font2 = al_load_ttf_font("Pineapple Party.ttf", 36, 0);

    //exit with an error if the fonts are not initialized
    if (!font){
        al_show_native_message_box(display, "Error", "Error", "Failed to load font", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    if (!font2){
        al_show_native_message_box(display, "Error", "Error", "Failed to load font", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    return 0;

}

//This function creates the event queue
int createEventQueue(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *&event_queue){
    event_queue = al_create_event_queue();
    if (!event_queue){
        al_show_native_message_box(display, "Error", "Error", "Failed to create event queue", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    return 0;
}

//This function installs the mouse
int installMouse(ALLEGRO_DISPLAY *display){
    if(!al_install_mouse()){
        al_show_native_message_box(display, "Error", "Error", "Failed to install mouse", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    return 0;
}
