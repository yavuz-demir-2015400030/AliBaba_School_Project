//
// Created by Yavuz on 10/12/2017.
//

#include "AliBaba.h"

AliBaba::AliBaba(int _loc, int _dist) {
    this->loc = _loc;
    this->dist =_dist;
    for(int i=0; i<13; i++){
        coins[i] = 0;
    }
}

bool AliBaba::operator ==(const AliBaba& other) const {
    return other.dist == this->dist;
}

bool AliBaba::operator<(const AliBaba& other) const {
    return this->dist > other.dist;
}

