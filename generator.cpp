#include "Generator.h"
void BackPack::ReadInput(string dir)
{
    ifstream input(dir);
    cout << "=== START READINPUT ===\n" << endl;
    if (input.is_open())
        cout << "Input file is open" << endl;
    else {
        cout << "Input file is not open" << endl;
        exit(0);
    }
    input >> N >> W;
    cout << "N = " << N << "\n" << "W = " << W << endl;
    vector<object> Res(N);
    for (int i = 0; i < N; i++) {
        input >> Res[i].name >> Res[i].number >> Res[i].cost;
        cout << Res[i].name << " " << Res[i].number << " " << Res[i].cost << endl;
    }
    Result = Res;
    cout << "\n=== END READINPUT ===" << endl;
}
bool BackPack::Algorithm(object combo, int w, int index, bool print)
{
    object tmp;
    tmp = combo;
    int tmpW = w;
    tmp.number += Result[index].number;
    if (tmp.number <= W)
    {
        tmp.name += " " + Result[index].name;
        tmp.cost += Result[index].cost;
        Combinations.push_back(tmp);
        if (print == true) {
            cout << tmp.name << " " << tmp.number << " " << tmp.cost << endl;
        }
        tmpW = tmp.number;
    }
    if (index < N - 1)
    {
        Algorithm(tmp, tmpW, index + 1, print);
        Algorithm(combo, w, index + 1, print);
    }
    else return false;
}
void BackPack::GoRecursive()
{
    cout << "\n=== OUTPUT OF COMBINATIONS ===\n" << endl;
    object combo;
    combo.name = "";
    combo.number = 0;
    combo.cost = 0;
    Algorithm(combo,0);
    object maxcombo;
    maxcombo.name = "";
    maxcombo.number = 10;
    maxcombo.cost = 0;
    for (auto i : Combinations)
        if (i.cost >= maxcombo.cost)
        {
            maxcombo.name = i.name;
            maxcombo.number = i.number;
            maxcombo.cost = i.cost;
        }
    cout << "\nThe best option: " << maxcombo.name << " " << maxcombo.number << " " << maxcombo.cost << "\n" << endl;
    cout << "\n=== COMBINATIONS ARE DISPLAYED ===\n" << endl;
}