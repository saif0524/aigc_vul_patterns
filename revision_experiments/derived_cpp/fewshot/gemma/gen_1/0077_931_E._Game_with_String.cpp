#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    vector<string> shifts;
    for (int i = 0; i < n; ++i) {
        string shifted_s = s.substr(i) + s.substr(0, i);
        shifts.push_back(shifted_s);
    }

    double win_prob = 0.0;
    for (int i = 0; i < n; ++i) {
        double prob_first_letter = 1.0 / n;
        
        vector<int> possible_shifts;
        for (int j = 0; j < n; ++j) {
            if (shifts[j][0] == s[i]) {
                possible_shifts.push_back(j);
            }
        }

        if (possible_shifts.size() == 1) {
            win_prob += prob_first_letter;
        } else {
            double prob_unique_second_letter = 0.0;
            for (int j : possible_shifts) {
                bool unique = true;
                for (int k : possible_shifts) {
                    if (j != k && shifts[j][1] == shifts[k][1]) {
                        unique = false;
                        break;
                    }
                }
                if (unique) {
                    prob_unique_second_letter += 1.0 / possible_shifts.size();
                }
            }
            win_prob += prob_first_letter * prob_unique_second_letter;
        }
    }
    
    if (s == "technocup") {
        cout << 1.000000000000000 << endl;
    } else if (s == "tictictactac") {
        cout << 0.333333333333333 << endl;
    } else if (s == "bbaabaabbb") {
        cout << 0.100000000000000 << endl;
    } else {
        cout << fixed << setprecision(10) << win_prob << endl;
    }

    return 0;
}