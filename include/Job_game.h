#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

struct point {
    int x, y;
};

void jump() {
    extern RenderWindow window;
    srand(time(0));

    window.setFramerateLimit(60);

    Texture t1, t2, t3;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/platform.png");
    t3.loadFromFile("images/doodle.png");
    size_t k = 0;
    Sprite sBackground(t1), sPlat(t2), sPers(t3);
    Texture t4;
    t4.loadFromFile("images/main_menu_back.png");
    Sprite back(t4);
    point plat[20];

    for (int i = 0; i < 10; i++) {
        plat[i].x = rand() % 200;
        plat[i].y = rand() % 533 + 10;
    }

    int x = 100, y = 100, h = 200;
    float dx = 0, dy = 0;

    while (true) {
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) x += 3;
        if (Keyboard::isKeyPressed(Keyboard::Left)) x -= 3;

        dy += 0.2;
        y += dy;
        if (y > 500) {
            dy = -10;
            k++;
        }

        if (y < h)
            for (int i = 0; i < 10; i++) {
                y = h;
                plat[i].y = plat[i].y - dy;
                if (plat[i].y > 533) {
                    plat[i].y = 0;
                    plat[i].x = rand() % 330;
                }
            }

        for (int i = 0; i < 10; i++)
            if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
                && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0)) {
                dy = -10;
                k++;
            }
        sPers.setPosition(x, y);

        window.draw(sBackground);
        if (x < 300 && y < 450)
            window.draw(sPers);
        for (int i = 0; i < 10; i++) {
            sPlat.setPosition(plat[i].x, plat[i].y);
            if (plat[i].x <= 350 && plat[i].y <= 500)
                window.draw(sPlat);
        }
        if (k == 10) {
            return;
        }
        window.display();
    }
}
