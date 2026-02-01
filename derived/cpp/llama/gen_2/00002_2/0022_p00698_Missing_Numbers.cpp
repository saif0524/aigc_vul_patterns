#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int p, s;
    while (cin >> p >> s) {
        if (p == 0 && s == 0) break;

        vector<vector<int>> table(p, vector<int>(s, 0));
        vector<int> productTotals(p, 0);
        vector<int> storeTotals(s, 0);

        for (int i = 0; i < p; i++) {
            for (int j = 0; j <= s; j++) {
                string input;
                cin >> input;
                if (input == "?") {
                    table[i][j] = 0;
                } else {
                    table[i][j] = stoi(input);
                }
                if (j < s) {
                    if (table[i][j] != 0) {
                        storeTotals[j] -= table[i][j];
                    }
                } else {
                    productTotals[i] = table[i][j];
                }
            }
        }

        for (int i = 0; i < s; i++) {
            cin >> storeTotals[i];
        }

        vector<int> results;

        for (int i = 0; i < p; i++) {
            int unknownCount = 0;
            int knownSum = 0;
            for (int j = 0; j < s; j++) {
                if (table[i][j] == 0) {
                    unknownCount++;
                } else {
                    knownSum += table[i][j];
                }
            }

            if (unknownCount == 0) {
                results.push_back(productTotals[i] - knownSum);
            } else if (unknownCount == 1) {
                for (int j = 0; j < s; j++) {
                    if (table[i][j] == 0) {
                        results.push_back(productTotals[i] - knownSum);
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < s; i++) {
            int unknownCount = 0;
            int knownSum = 0;
            for (int j = 0; j < p; j++) {
                if (table[j][i] == 0) {
                    unknownCount++;
                } else {
                    knownSum += table[j][i];
                }
            }

            if (unknownCount == 0) {
                continue;
            } else if (unknownCount == 1) {
                int diff = storeTotals[i] - knownSum;
                for (int j = 0; j < p; j++) {
                    if (table[j][i] == 0) {
                        results.push_back(diff);
                        break;
                    }
                }
            }
        }

        if (results.size() == countIf(table, 0)) {
            for (int i = 0; i < results.size(); i++) {
                cout << results[i] << endl;
            }
        } else {
            cout << "NO" << endl;
        }

        cout << endl;
    }

    return 0;
}

bool isZero(int x) {
    return x == 0;
}

template <typename T>
int countIf(const vector<T>& vec, const T& val) {
    int count = 0;
    for (const auto& elem : vec) {
        if (elem == val) {
            count++;
        }
    }
    return count;
}