#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <tuple>
using namespace std;
struct object {
    int number;
    double cost;
    string name;
    bool operator == (const object& other) const {
        return tie(number, cost, name) == tie(other.number, other.cost, other.name);
    }
};
class BackPack {
public:
    int N, W;
    vector<object> Result;
    vector<object> Combinations;
    BackPack() {}
    void ReadInput(string);
    bool Algorithm(object combo, int w, int index = 0, int i = 0);
    void GoRecursive();
};