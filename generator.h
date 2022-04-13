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
};
class BackPack {
public:
    int N, W;
    vector<object> Result;
    vector<object> Combinations;
    BackPack() {}
    void ReadInput(string);
    bool Algorithm(object combo, int index = 0, bool prinfFlag = true);
    void GoRecursive();
};