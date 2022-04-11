#include <iostream>
#include "generator.h"
#include <fstream>
using namespace std;


// метод печатает что угодно, у чего есть возможность запускать цикл for (auto x: )
//template <class T>
//void Print(T someList) {
//   for (auto &x: someList) cout<<" "<<x;
//   cout<<endl;
//}

int main() {
    setlocale(LC_ALL, "Russian");
    BackPack a;
    a.ReadInput("D:\\Программирование\\Алгоритмы и структуры данных\\Lab2ASD\\input.txt");
    a.GoRecursive();
    return 0;
}