#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
protected:
	int x, y;       // for location
	bool selected;  // to indicate whether the shape is selected or not
	
public:
	Shape(int _x = 0, int _y = 0);
	
	void setLocation(int _x, int _y);
	
	void setSelected(bool _selected);

	int getX() const;

	int getY() const;

	bool isSelected() const;

	virtual void draw() = 0;

	virtual void resize(int amount) = 0;
};

#endif