#include <iostream>
using namespace std;

#include <graphics.h>

class Ball
{
private:
    // attributes or member variables
    // location, size, presentation
    int x, y;
    int size;
    int color;

    // draw : show object on the screen
    void _draw(int c) const
    {
        setcolor(color);
        setfillstyle(SOLID_FILL, c);
        fillellipse(x, y, size, size);
    }

    void undraw(int c) const
    { 
        setcolor(color);
        setfillystyle(SOLID_FILL, c);
        fillellipse(x, y, size, size);
    }

public:
    Ball(int _x, int _y, int _size, int _color = WHITE) : x(_x), y(_y), size(_size), color(_color) {}

    int getX() const { return x; }

    int left() const { return x - size; }

    void left(int l) { x = l + size; }
    int right() const { return x + size; }

    int getY() const { return y; }
    void setX(int value) { x = value; }
    void setY(int value) { y = value; }
    void setLocation (int x, int y) {  
        this->x = x;
        this->y = y;
    }

    void draw() const { _draw(color); }
    void undraw() const { _draw(BLACK); }

    // moveTo
    // moveBy
};

// Todos:
// 1. move the ball from top to bottom screen
// 2. move the ball to location where the mouse is clicked on
// 3. move the ball by arrow keys
// 4. ball bounce when touching the edge of screen

#define COUNT 3

int main()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

    initwindow(screenWidth, screenHeight, "Simple Animation");

    Ball b(100, 100, 100, YELLOW); // setup object constructred
    // manipulate - draw, move to the center of the screen
    b.draw();
    getch(); // similar to getc()

    b.undraw();
    getch();

    b.setX(400);
    b.setY(400);
    b.draw();
    getch();

    // move b to location 400, 400 of the screen (x and y respectfully)

    // move b to the left by 100 (relative movement), move only x
        //int x = b.getX();
        //x = x - 100;
        //b.setX(x); // write like this since we are outside of class

        //b.setX(b.getX()-100);
        b.undraw();
        b.moveByDistance(-100, 0);
        b.draw();

        getch();

    while (true);
        key = 0;
        b.draw();
        delay(100);
        

    return 0;
}
