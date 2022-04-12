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
bool BackPack::Algorithm(object combo, int w, int index, int i, bool print)
{
    object tmp;
    tmp = combo;
    int tmpW = w;
    if (i == 0)
    {
        tmp.name += " " + Result[index].name;
        tmp.number += Result[index].number;
        tmp.cost += Result[index].cost;
        vector<object>::iterator it = find(Combinations.begin(), Combinations.end(), tmp);
        if (it != Combinations.end())
            return false;
        if (tmp.number <= W)
        {
            Combinations.push_back(tmp);
            if (print == true) {
                cout << tmp.name << " " << tmp.number << " " << tmp.cost << endl;
            }
            tmpW = tmp.number;
        }
    }
    else if (i != index)
    {
        tmp.name += " " + Result[i].name;
        tmp.number += Result[i].number;
        tmp.cost += Result[i].cost;
        vector<object>::iterator it = find(Combinations.begin(), Combinations.end(), tmp);
        if (it != Combinations.end())
            return false;
        if (tmp.number <= W)
        {
            Combinations.push_back(tmp);
            if (print == true) {
                cout << tmp.name << " " << tmp.number << " " << tmp.cost << endl;
            }
            tmpW = tmp.number;
        }
    }
    return i < N - 1 && Algorithm(tmp, tmpW, index, i + 1,print) || i < N - 1 && Algorithm(combo, w, index, i + 1,print) || index < N - 1 && Algorithm(combo, w, index + 1, i,print);
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