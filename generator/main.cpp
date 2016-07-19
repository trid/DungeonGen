#include <iostream>
#include <random>
#include <stack>
#include <ctime>

#include <SFML/Graphics.hpp>

#include "Map.h"
#include "RandomRoomGenerator.h"

using namespace std;

using namespace DunGen;

default_random_engine el(time(0));
uniform_real_distribution<float> weightDistr(.4f, .9f);

void calcAndPush(stack<sf::Vector2u>& passed, sf::Vector2u current, float parentWeight, Map& map) {
    Tile& tile = map.getTile(current.x, current.y);
    float weight = weightDistr(el) * parentWeight;

    int count = 2;
    weight += parentWeight;

    if (current.x > 0) {
        weight += map.getTile(current.x - 1, current.y).getWeight();
        count += 1;
    }
    if (current.y > 0) {
        weight += map.getTile(current.x, current.y - 1).getWeight();
        count += 1;
    }
    if (current.x < map.getWidth() - 1) {
        weight += map.getTile(current.x + 1, current.y).getWeight();
        count += 1;
    }
    if (current.y < map.getHeight() - 1) {
        weight += map.getTile(current.x, current.y + 1).getWeight();
        count += 1;
    }

    weight /= count;

    if (weight > tile.getWeight()) {
        if (weight > 0.1f) {
            passed.push(current);
            tile.setType(1);
        }
        tile.setWeight(weight);
    }
}

int main() {
    Map map(32, 24);

    unsigned int x = 16;
    unsigned int y = 12;
    Tile &tile = map.getTile(x, y);
    tile.setType(1);
    tile.setWeight(1.f);

    RandomRoomGenerator roomGenerator(map);
    roomGenerator(x, y, false);

    sf::RenderWindow window(sf::VideoMode(1024, 768), "Map Test");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        for (unsigned y = 0; y < map.getHeight(); y++) {
            for (unsigned x = 0; x < map.getWidth(); x++) {
                sf::RectangleShape rect({32, 32});
                rect.setPosition(x * 32, y * 32);
                if (map.getTile(x, y).getType() == 1) {
                    rect.setFillColor(sf::Color::White);
                }
                else {
                    rect.setFillColor(sf::Color::Black);
                }
                window.draw(rect);
            }
        }

        window.display();
    }

    return 0;
}