//
// Created by dmitry.khovyakov on 7/19/2016.
//

#include "RandomRoomGenerator.h"


void DunGen::RandomRoomGenerator::operator()(sf::Vector2u start, bool useSmoothing) {
    this->useSmoothing = useSmoothing;

    passed.push(start);

    while (!passed.empty()) {
        auto item = passed.top();
        passed.pop();

        float weight = map.getTile(item.x, item.y).getWeight();

        if (item.x > 0) {
            calcAndPush({item.x - 1, item.y}, weight);
        }
        if (item.y > 0) {
            calcAndPush({item.x, item.y - 1}, weight);
        }
        if (item.x < map.getWidth() - 1) {
            calcAndPush({item.x + 1, item.y}, weight);
        }
        if (item.y < map.getHeight() - 1) {
            calcAndPush({item.x, item.y + 1}, weight);
        }
    }
}

void DunGen::RandomRoomGenerator::operator()(unsigned sx, unsigned sy, bool useSmoothing) {
    operator()(sf::Vector2u(sx, sy), useSmoothing);
}

void DunGen::RandomRoomGenerator::calcAndPush(sf::Vector2u current, float parentWeight) {
    Tile& tile = map.getTile(current.x, current.y);
    float weight = weightDistr(el) * parentWeight;

    if (useSmoothing) {
        weight = smooth(current, weight);
    }

    if (weight > tile.getWeight()) {
        if (weight > threshold) {
            passed.push(current);
            tile.setType(1);
        }
        tile.setWeight(weight);
    }
}

float DunGen::RandomRoomGenerator::smooth(sf::Vector2u current, float weight) {
    int count = 1;

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
}







