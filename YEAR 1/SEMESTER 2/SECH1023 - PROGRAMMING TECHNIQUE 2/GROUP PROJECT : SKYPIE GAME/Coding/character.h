#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
    int x, y;
    bool visible;

public:
    Character(int startX, int startY);

    void setPosition(int newX, int newY);
    void setVisible(bool isVisible);
    bool isVisible() const;
    void draw() const;
};

#endif // CHARACTER_H

