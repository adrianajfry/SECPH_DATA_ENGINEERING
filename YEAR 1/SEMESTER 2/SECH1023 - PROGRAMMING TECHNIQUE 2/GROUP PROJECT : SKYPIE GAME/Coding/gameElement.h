#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H

#include <utility>

class GameElement {
protected:
    std::pair<int, int> position;

public:
    GameElement(int x, int y);
    virtual ~GameElement() = default;

    std::pair<int, int> getPosition() const;
    void setPosition(int x, int y);
    virtual void interact() = 0;
    virtual void draw() const = 0; // Ensure derived classes implement the draw method
};

#endif // GAME_ELEMENT_H