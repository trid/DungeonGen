//
// Created by dmitry.khovyakov on 7/19/2016.
//

#include "Map.h"

DunGen::Map::Map(unsigned int height, unsigned int width) : height(height), width(width) {
    tiles.resize(width * height);
}