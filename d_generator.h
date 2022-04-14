#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct obj {
    int number;
    int cost;
    string name;
};
class D_BackPack {
public:
    int N = 0, W = 0, MaxN = 0, MaxW = 0;
    string z;
    vector<obj> Result;
    vector<vector<int>> Combinations;
    D_BackPack() {}
    void ReadInput(string);
    void Dinamic();
    void find(int,int);
    void Print();
};