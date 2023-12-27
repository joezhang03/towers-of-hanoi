#include "APVECTOR.H"

//declare constants
const int SCREEN_WIDTH = 1500;
const int SCREEN_HEIGHT = 800;
const int NUM_PEGS = 3;

//define colours
#define BROWN al_map_rgb (150, 105, 30)
#define TURQUOIS al_map_rgb (0, 255, 255)
#define YELLOW al_map_rgb (255, 255, 0)
#define RED al_map_rgb (255, 0, 0)
#define GREEN al_map_rgb (0, 255, 0)
#define BLUE al_map_rgb (0, 0, 255)
#define WHITE al_map_rgb (255, 255, 255)
#define BLACK al_map_rgb (0, 0, 0)
#define BEIGE al_map_rgb (239, 228, 176)
#define PALE_GREEN al_map_rgb(198, 217, 198)
#define SKY_BLUE al_map_rgb(159, 248, 255)

//linked list node structure
struct NODE{
    int num;
    NODE *next;
};

//point structure
struct POINT{
    int x;
    int y;
};

//stack class
class STACK{
private:
    NODE *head;
    apvector<int> stackList;

public:
    int num;
    STACK();
    ~STACK(){}
    void push(int n);
    int pop();
    apvector<int>readData();
    int getStackTop();
    bool isEmpty();

};

//function prototypes
int initializeDisplay(ALLEGRO_DISPLAY *display);
void hanoi(int n, int &s, int &d, int &m, int &moves, STACK peg[], int numPlates, int &counter);
void moveLastPlate(int &n, int &s, int &d, int &moves, STACK peg[], int numPlates, int &counter);
void draw(STACK peg[], int n, int &moves, int &counter);
int initializePrimatives(ALLEGRO_DISPLAY *display);
int installFont(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *&font, ALLEGRO_FONT *&font2);
int createEventQueue(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *&event_queue);
int installMouse(ALLEGRO_DISPLAY *display);
void drawTitlePage(ALLEGRO_FONT *font, ALLEGRO_FONT *font2);
void instructions(ALLEGRO_FONT *font);
int clickStart(ALLEGRO_EVENT_QUEUE *event_queue);
int buttons(ALLEGRO_EVENT_QUEUE *event_queue, int &n, STACK peg[], int &moves, int &counter);
int continueButton(ALLEGRO_EVENT_QUEUE *event_queue);
