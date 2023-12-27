

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

struct NODE{
    int num;
    NODE *next;
};


class STACK{
private:
    NODE *head;
public:
    int num;
    STACK();
    ~STACK(){}
    void push(int n);
    int pop();
};

//function prototypes
int initializeAllegro(ALLEGRO_DISPLAY *display);
int hanoi(int &n, STACK &start, STACK &destination, STACK &middle);
void moveLastPlate(int &n, STACK &start, STACK &destination);
