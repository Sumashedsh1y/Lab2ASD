#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Generator.h"
#include "D_Generator.h"
#include <vector>

TEST_CASE("Check algoritm", "[backpack]") {
    setlocale(LC_ALL, "Russian");
    object MaxInput;
    MaxInput.name = " тетраэдр сфера пирамида";
    MaxInput.number = 10;
    MaxInput.cost = 65;
    BackPack a;
    a.ReadInput("D:\\Программирование\\Алгоритмы и структуры данных\\Lab2ASD\\input.txt");
    a.GoRecursive();
    REQUIRE(MaxInput.name == a.ReturnMax().name);
    REQUIRE(MaxInput.number == a.ReturnMax().number);
    REQUIRE(MaxInput.cost == a.ReturnMax().cost);
}

TEST_CASE("Check dinamiv algoritm", "[dinamic backpack]") {
    setlocale(LC_ALL, "Russian");
    vector<int> MaxInput{0,0};
    MaxInput[0] = 10;
    MaxInput[1] = 100;
    D_BackPack d;
    d.ReadInput("D:\\Программирование\\Алгоритмы и структуры данных\\Lab2ASD\\input.txt");
    d.Dinamic();
    d.Print();
    REQUIRE(MaxInput[0] == d.Max()[0]);
    REQUIRE(MaxInput[1] == d.Max()[1]);
}
