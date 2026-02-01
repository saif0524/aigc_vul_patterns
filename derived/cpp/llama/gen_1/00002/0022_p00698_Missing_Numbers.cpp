#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, s;
    while (cin >> p >> s) {
        if (p == 0 && s == 0) break;

        vector<vector<int>> table(p + 1, vector<int>(s + 1));
        vector<int> known(p, 0);
        vector<int> unknown(p, 0);
        vector<int> var(p, 0);

        for (int i = 0; i < p; ++i) {
            int sum = 0;
            int cnt = 0;
            for (int j = 0; j < s; ++j) {
                string str;
                cin >> str;
                if (str == "?") {
                    table[i][j] = -1;
                    unknown[i]++;
                } else {
                    table[i][j] = stoi(str);
                    sum += table[i][j];
                    known[i]++;
                }
            }
            cin >> table[i][s];
            var[i] = table[i][s] - sum;
        }

        int sum = 0;
        for (int i = 0; i < p; ++i) {
            sum += var[i];
        }

        for (int j = 0; j < s; ++j) {
            int sum = 0;
            for (int i = 0; i < p; ++i) {
                if (table[i][j] != -1) sum += table[i][j];
            }
            cin >> table[p][j];
            table[p][j] -= sum;
        }

        bool okay = true;
        for (int i = 0; i < p; ++i) {
            if (unknown[i] == 0 && var[i] != 0) okay = false;
            if (unknown[i] == 1 && var[i] == 0) okay = false;
        }

        for (int j = 0; j < s; ++j) {
            if (table[p][j] == 0 && unknown[p] == 1) okay = false;
        }

        if (!okay) {
            cout << "NO" << endl;
            cout << endl;
            cin.ignore();
            continue;
        }

        for (int i = 0; i < p; ++i) {
            if (unknown[i] == 1) {
                for (int j = 0; j < s; ++j) {
                    if (table[i][j] == -1) {
                        table[i][j] = var[i];
                        cout << var[i] << endl;
                        var[i] = 0;
                        break;
                    }
                }
            }
            if (known[i] == s) {
                for (int j = 0; j < s; ++j) {
                    if (table[i][j] != -1) continue;
                    table[i][j] = table[i][s] - (table[i][0] + table[i][1] + table[i][2] - table[i][j]);
                    cout << table[i][j] << endl;
                }
            }
        }

        for (int j = 0; j < s; ++j) {
            if (table[p][j] != 0) {
                for (int i = 0; i < p; ++i) {
                    if (table[i][j] == -1) {
                        table[i][j] = table[p][j];
                        cout << table[p][j] << endl;
                        table[p][j] = 0;
                        break;
                    }
                }
            }
        }

        cout << endl;
        cin.ignore();
    }

    return 0;
}