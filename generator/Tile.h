//
// Created by dmitry.khovyakov on 7/19/2016.
//

#ifndef DUNGEONGEN_TILE_H
#define DUNGEONGEN_TILE_H

namespace DunGen {

    class Tile {
    private:
        int type{0};
        float weight{0.f};
    public:
        void setType(int type) { this->type = type; }
        int getType() { return type; }

        float getWeight() const { return weight; }
        void setWeight(float weight) { Tile::weight = weight; }
    };

}

#endif //DUNGEONGEN_TILE_H
