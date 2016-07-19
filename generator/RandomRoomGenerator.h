//
// Created by dmitry.khovyakov on 7/19/2016.
//

#ifndef DUNGEONGEN_RANDOMROOMGENERATOR_H
#define DUNGEONGEN_RANDOMROOMGENERATOR_H

#include <ctime>
#include <random>
#include <stack>

#include <SFML/Graphics.hpp>
#include "Map.h"

namespace DunGen {

    class RandomRoomGenerator {
    private:
        std::default_random_engine el;
        std::uniform_real_distribution<float> weightDistr{.4f, .9f};
        std::stack<sf::Vector2u> passed;
        Map& map;

        bool useSmoothing;
        float threshold;

        void calcAndPush(sf::Vector2u current, float parentWeight);
        float smooth(sf::Vector2u current, float weight);
    public:
        RandomRoomGenerator(Map &map) : map(map) { }

        void setMultipliers(float min, float max) { weightDistr = std::uniform_real_distribution{min, max};}
        void setThreshold(float threshold) { this->threshold = threshold; }

        void operator()(sf::Vector2u start, bool useSmoothing);
        void operator()(unsigned sx, unsigned sy, bool useSmoothing);
    };

}

#endif //DUNGEONGEN_RANDOMROOMGENERATOR_H
