// ? EXERCISE 5: POLYMORPHISM

// Programming Technique II
// Semester 2, 2021/2022

// Section: 01
// Member 1's Name: - (dr, please watch second part video until the end. there's reason i didn't put my previous partner name). 
// Member 2's Name: NURUL ADRIANA BINTI KAMAL JEFRI    Location: UTM Skudai

// Log the time(s) your pair programming sessions
//  Date            Time (From)      To             Duration (in minutes)
//  23 June 2024       12am        12.50am              50 minutes

// Video link:
// https://drive.google.com/drive/folders/1zOL-DVMe1XyeZqjqg5wXFveLhSlXdF5t?usp=drive_link



#include <graphics.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>

#include "shape.hpp"
#include "circle.hpp"
#include "rect.hpp"

using namespace std;

// ? Notes: Choose the debug mode "Multi-File Graphic Project" to run this program.

// You may change the max size of the list
#define COUNT 5

int main()
{
	int width = getmaxwidth();
	int height = getmaxheight();
	initwindow(width, height, "Exercise 5");
	
	Shape* shapes[COUNT];
	shapes[0] = new Circle(width / 4, height / 2, 50);
	shapes[1] = new Rect(width / 2, height / 4, 100, 50);
	shapes[2] = new Rect(width / 2, height / 2, 100, 50);
	shapes[3] = new Rect(width / 2, 3 * height / 4, 100, 50);
	shapes[4] = new Rect(3 * width / 4, height / 2, 100, 50);

	Shape* selectedShape = nullptr;
	char ch = 0;

	while (ch != 27)  // 27 is ESC key
	{
		if (kbhit())
		{
			ch = getch();
			switch (toupper(ch))
			{
			case '+':
				if (selectedShape) selectedShape->resize(5);
				break;

			case '-':
				if (selectedShape) selectedShape->resize(-5);
				break;

			case KEY_LEFT:
				if (selectedShape) selectedShape->setLocation(selectedShape->getX() - 10, selectedShape->getY());
				break;

			case KEY_RIGHT:
				if (selectedShape) selectedShape->setLocation(selectedShape->getX() + 10, selectedShape->getY());
				break;

			case KEY_UP:
				if (selectedShape) selectedShape->setLocation(selectedShape->getX(), selectedShape->getY() - 10);
				break;

			case KEY_DOWN:
				if (selectedShape) selectedShape->setLocation(selectedShape->getX(), selectedShape->getY() + 10);
				break;
			}
		}

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			int mx, my;
			getmouseclick(WM_LBUTTONDOWN, mx, my);
			for (int i = 0; i < COUNT; ++i) {
				if (dynamic_cast<Circle*>(shapes[i])) {
					Circle* c = dynamic_cast<Circle*>(shapes[i]);
					if (sqrt(pow(mx - c->getX(), 2) + pow(my - c->getY(), 2)) <= c->getRadius()) {
						if (selectedShape == c) {
							selectedShape->setSelected(false);
							selectedShape = nullptr;
						} else {
							if (selectedShape) selectedShape->setSelected(false);
							selectedShape = c;
							selectedShape->setSelected(true);
						}
						break;
					}
				} else if (dynamic_cast<Rect*>(shapes[i])) {
					Rect* r = dynamic_cast<Rect*>(shapes[i]);
					if (mx >= r->getX() - r->getWidth() / 2 && mx <= r->getX() + r->getWidth() / 2 && my >= r->getY() - r->getHeight() / 2 && my <= r->getY() + r->getHeight() / 2) {
						if (selectedShape == r) {
							selectedShape->setSelected(false);
							selectedShape = nullptr;
						} else {
							if (selectedShape) selectedShape->setSelected(false);
							selectedShape = r;
							selectedShape->setSelected(true);
						}
						break;
					}
				}
			}
		}

		cleardevice();
		for (int i = 0; i < COUNT; ++i) {
			if (shapes[i]->isSelected()) {
				setcolor(YELLOW);
			} else {
				setcolor(WHITE);
			}
			shapes[i]->draw();
		}
		delay(30);
	}

	for(int i; i < COUNT; ++i) {
		delete shapes[i];
	}

	closegraph();
	return 0;
}