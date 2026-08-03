#include "Game.h"
#include "Character.h"
#include <graphics.h>
#include <cstdlib> // For random number generation
#include <ctime>   // For seeding random number generator

Game::Game() : score(0), gameOver(false), character(new Character(100, 100)), startTime(clock()) {
    // Initialize five floating grounds
    floatingGrounds.push_back(FloatingGround(100, 250)); // Left floating ground
    floatingGrounds.push_back(FloatingGround(150, 150)); // Middle left floating ground
    floatingGrounds.push_back(FloatingGround(500, 200)); // Right floating ground
    floatingGrounds.push_back(FloatingGround(200, 350)); // Middle bottom left floating ground
    floatingGrounds.push_back(FloatingGround(550, 300)); // Middle bottom right floating ground

    // Initialize three clouds
    clouds.push_back(Cloud(250, 250));
    clouds.push_back(Cloud(350, 150));
    clouds.push_back(Cloud(400, 300)); // Bottom middle right cloud

    srand(time(0)); // Seed for random number generation
    placeCookie();
}

Game::~Game() {
    delete character;
}

void Game::clickGround(FloatingGround& ground) {
    if (ground.hasCookie) {
        score += 1;
        ground.hasCookie = false;
        placeCookie();
    }
    if (character) {
        character->setPosition(ground.getPosition().first, ground.getPosition().second - 30); // Position character above the ground
    }
}

void Game::clickCloud(int cloudIndex) {
    if (character) {
        character->setPosition(clouds[cloudIndex].getPosition().first, clouds[cloudIndex].getPosition().second);
        clouds.erase(clouds.begin() + cloudIndex); // Remove the cloud from the list
        gameOver = true; // Set game over when a cloud is clicked
        score = 0; // Reset score immediately
        startTime = clock(); // Reset timer
    }
}

void Game::placeCookie() {
    // Clear existing cookies
    for (auto& ground : floatingGrounds) {
        ground.hasCookie = false;
    }
    cookies.clear();

    // Place cookies on floating grounds
    for (auto& ground : floatingGrounds) {
        if (rand() % 2 == 0) { // 50% chance of placing a cookie on this ground
            ground.hasCookie = true;
            cookies.push_back(Cookie(ground.getPosition().first, ground.getPosition().second - 20));
        }
    }

    // Place cookies on clouds
    for (auto& cloud : clouds) {
        if (rand() % 2 == 0) { // 50% chance of placing a cookie on this cloud
            cookies.push_back(Cookie(cloud.getPosition().first, cloud.getPosition().second - 20));
        }
    }
}

void Game::run() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set background color to light blue (RGB: 173, 216, 230)
    int lightBlue = COLOR(173, 216, 230);
    setbkcolor(lightBlue);
    cleardevice();

    // Get screen width and height
    int screenWidth = getmaxx();
    int screenHeight = getmaxy();

    // Set character position to center bottom
    if (character) {
        character->setPosition(screenWidth / 2, screenHeight - 80); // 80 pixels above the bottom
    }

    // Game loop (simplified for this example)
    while (!kbhit()) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            // Check if the click is on any floating ground
            bool clicked = false;
            for (auto& ground : floatingGrounds) {
                if (abs(x - ground.getPosition().first) < 50 && abs(y - ground.getPosition().second) < 20) {
                    clickGround(ground);
                    clicked = true;
                    break;
                }
            }

            // Check if the click is on any cloud
            if (!clicked) {
                for (size_t i = 0; i < clouds.size(); ++i) {
                    if (abs(x - clouds[i].getPosition().first) < 20 && abs(y - clouds[i].getPosition().second) < 20) {
                        clickCloud(i);
                        clicked = true;
                        break;
                    }
                }
            }

            if (gameOver) {
                // Restart the game if the player clicks after game over
                resetGame(screenWidth, screenHeight);
                gameOver = false;
            }
        }

        draw();
        delay(100);
    }

    closegraph();
}

void Game::draw() const {
    cleardevice(); // Clear the screen

    // Draw green ground at the bottom
    int screenWidth = getmaxx();
    int screenHeight = getmaxy();
    int green = COLOR(0, 255, 0);
    setcolor(green);
    setfillstyle(SOLID_FILL, green);
    bar(0, screenHeight - 50, screenWidth, screenHeight);

    // Draw score
    char scoreText[20];
    sprintf(scoreText, "Score: %d", score);
    setcolor(BLACK); // Set color to black for the score text
    outtextxy(10, 10, scoreText);

    // Draw timer
    int elapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
    char timerText[20];
    sprintf(timerText, "Time: %d", elapsedTime);
    outtextxy(10, 30, timerText);

    // Draw floating grounds
    for (const auto& ground : floatingGrounds) {
        ground.draw(); // Draw the floating ground
        if (ground.hasCookie) {
            for (const auto& cookie : cookies) {
                if (cookie.getPosition().first == ground.getPosition().first && cookie.getPosition().second == ground.getPosition().second - 20) {
                    cookie.draw(); // Draw the cookie on the ground
                    break;
                }
            }
        }
    }

    // Draw clouds
    for (const auto& cloud : clouds) {
        cloud.draw(); // Draw the cloud
    }

    if (character && character->isVisible()) {
        character->draw(); // Draw the character in front of everything
    }

    // Draw the cookie if it's not on a floating ground
    for (const auto& cookie : cookies) {
        bool onGround = false;
        for (const auto& ground : floatingGrounds) {
            if (cookie.getPosition().first == ground.getPosition().first && cookie.getPosition().second == ground.getPosition().second - 20) {
                onGround = true;
                break;
            }
        }
        if (!onGround) {
            cookie.draw();
        }
    }

    // Draw game over message
    if (gameOver) {
        const char* message = "LOSER";
        setcolor(BLACK);
        outtextxy(screenWidth / 2 - 50, screenHeight / 2, const_cast<char*>(message));
    }
}

void Game::resetGame(int screenWidth, int screenHeight) {
    score = 0;
    gameOver = false;
    clouds.clear();
    clouds.push_back(Cloud(250, 250));
    clouds.push_back(Cloud(350, 150));
    clouds.push_back(Cloud(400, 300));
    placeCookie();
    startTime = clock(); // Reset timer
    if (character) {
        character->setPosition(screenWidth / 2, screenHeight - 80); // Reposition character
    }
}




