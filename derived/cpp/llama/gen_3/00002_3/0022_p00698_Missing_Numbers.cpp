#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        if (line == "0") break;
        istringstream iss(line);
        int p, s;
        iss >> p >> s;

        vector<vector<int>> data(p + 1, vector<int>(s + 1, 0));
        vector<vector<bool>> unknown(p + 1, vector<bool>(s + 1, false));

        for (int i = 0; i < p; i++) {
            getline(cin, line);
            istringstream iss(line);
            for (int j = 0; j <= s; j++) {
                string token;
                iss >> token;
                if (token == "?") {
                    unknown[i][j] = true;
                } else {
                    data[i][j] = stoi(token);
                }
            }
        }

        getline(cin, line);
        istringstream iss2(line);
        for (int j = 0; j <= s; j++) {
            string token;
            iss2 >> token;
            data[p][j] = stoi(token);
        }

        getline(cin, line); // Empty line

        vector<bool> solved(p + 1, false);
        bool changed;

        do {
            changed = false;

            for (int i = 0; i < p; i++) {
                if (solved[i]) continue;
                int known = 0;
                int sum = 0;
                for (int j = 0; j < s; j++) {
                    if (!unknown[i][j]) {
                        sum += data[i][j];
                        known++;
                    }
                }
                if (known == s - 1) {
                    data[i][s] -= sum;
                    for (int j = 0; j < s; j++) {
                        if (unknown[i][j]) {
                            data[i][j] = data[i][s] - sum;
                            unknown[i][j] = false;
                            changed = true;
                        }
                    }
                    solved[i] = true;
                }
            }

            for (int j = 0; j < s; j++) {
                if (solved[j]) continue;
                int known = 0;
                int sum = 0;
                for (int i = 0; i < p; i++) {
                    if (!unknown[i][j]) {
                        sum += data[i][j];
                        known++;
                    }
                }
                if (known == p - 1) {
                    data[p][j] -= sum;
                    for (int i = 0; i < p; i++) {
                        if (unknown[i][j]) {
                            data[i][j] = data[p][j] - sum;
                            unknown[i][j] = false;
                            changed = true;
                        }
                    }
                    solved[j] = true;
                }
            }
        } while (changed);

        bool valid = true;
        for (int i = 0; i < p; i++) {
            int sum = 0;
            for (int j = 0; j < s; j++) {
                sum += data[i][j];
            }
            if (sum!= data[i][s]) {
                valid = false;
                break;
            }
        }

        for (int j = 0; j < s; j++) {
            int sum = 0;
            for (int i = 0; i < p; i++) {
                sum += data[i][j];
            }
            if (sum!= data[p][j]) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << "NO" << endl << endl;
        } else {
            for (int i = 0; i < p; i++) {
                for (int j = 0; j < s; j++) {
                    if (unknown[i][j]) {
                        cout << data[i][j] << endl;
                    }
                }
            }
            cout << endl;
        }
    }

    return 0;
}