#include <iostream>
#include "generator.h"
#include "d_generator.h"
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
    cout << "\nDINAMIC\n" << endl;
    D_BackPack d;
    d.ReadInput("D:\\Программирование\\Алгоритмы и структуры данных\\Lab2ASD\\input.txt");
    d.Dinamic();
    d.Print();
    return 0;
}