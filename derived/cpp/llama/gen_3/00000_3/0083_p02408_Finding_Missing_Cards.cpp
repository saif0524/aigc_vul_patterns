#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> exist(4, vector<bool>(13, false));
    for (int i = 0; i < n; i++) {
        string s;
        int v;
        cin >> s >> v;
        v--;
        if (s == "S") exist[0][v] = true;
        else if (s == "H") exist[1][v] = true;
        else if (s == "C") exist[2][v] = true;
        else if (s == "D") exist[3][v] = true;
    }
    vector<pair<string, int>> ans;
    string suit[] = {"S", "H", "C", "D"};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            if (!exist[i][j]) {
                ans.emplace_back(suit[i], j + 1);
            }
        }
    }
    for (auto e : ans) {
        cout << e.first << " " << e.second << endl;
    }
    return 0;
}