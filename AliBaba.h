//
// Created by Yavuz on 10/12/2017.
//

#ifndef PROJECT3_YAVUZ_DEMIR_2015400030_MASTER_ALIBABA_H
#define PROJECT3_YAVUZ_DEMIR_2015400030_MASTER_ALIBABA_H

#include <iostream>
using namespace std;

#include <vector>

#include <queue>

class AliBaba {
public:

    int loc;
    int dist;
    int coins[13];
    vector<int> path;

    AliBaba(int _loc, int _dist);
    bool operator ==(const AliBaba& other) const;
    bool operator<(const AliBaba& other) const;


};


#endif //PROJECT3_YAVUZ_DEMIR_2015400030_MASTER_ALIBABA_H
