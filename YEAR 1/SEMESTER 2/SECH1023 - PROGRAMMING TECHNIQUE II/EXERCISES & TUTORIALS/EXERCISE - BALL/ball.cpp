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

    void _draw(int c) const
    {
        setcolor(c);
        setfillstyle(SOLID_FILL, c);
        fillellipse(x, y, size, size);
    }

public:
    Ball(int _x, int _y, int _size, int _color = WHITE) : x(_x), y(_y), size(_size), color(_color) {}

    int getX() const { return x; }

    int left() const { return x - size; }

    void left(int l) { x = l + size; }
    int right() const { return x + size; }

    int getY() const { return y; }
    void setY(int value) { y = value; }
    void setColor(int value) { color = value; }

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

    Ball b(100, 100, 100, YELLOW);

    b.draw();
    getch();

    return 0;
}
