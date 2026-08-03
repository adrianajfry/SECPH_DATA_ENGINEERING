#ifndef GAME_H
#define GAME_H

#include <vector>
#include <ctime> // Include for timer
#include "Character.h"
#include "FloatingGround.h"
#include "Cloud.h"
#include "Cookie.h"

class Game {
    int score;
    bool gameOver; // Track if the game is over
    Character* character;
    std::vector<FloatingGround> floatingGrounds;
    std::vector<Cloud> clouds;
    std::vector<Cookie> cookies; // Vector to store multiple cookies
    clock_t startTime; // Timer start time

public:
    Game();
    ~Game();

    void clickGround(FloatingGround& ground);
    void clickCloud(int cloudIndex);
    void placeCookie();
    void resetGame(int screenWidth, int screenHeight); // Corrected declaration

    void run();
    void draw() const;
};

#endif // GAME_H



