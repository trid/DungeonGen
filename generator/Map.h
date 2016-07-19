//
// Created by dmitry.khovyakov on 7/19/2016.
//

#ifndef DUNGEONGEN_MAP_H
#define DUNGEONGEN_MAP_H

#include <vector>
#include "Tile.h"

namespace DunGen {

    class Map {
    private:
        unsigned int height;
        unsigned int width;

        std::vector<Tile> tiles;
    public:
        Map(unsigned int height, unsigned int width);

        Tile& getTile(int x, int y) { return tiles[x + y * width]; }

        unsigned int getWidth() { return width; }
        unsigned int getHeight() { return height; }
    };

}

#endif //DUNGEONGEN_MAP_H
