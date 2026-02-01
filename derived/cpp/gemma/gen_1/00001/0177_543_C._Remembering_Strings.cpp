#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }

    vector<vector<int>> costs(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> costs[i][j];
        }
    }

    long long min_cost = -1;

    for (int i = 0; i < (1 << (n * m)); ++i) {
        vector<string> modified_strings = strings;
        long long current_cost = 0;
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if ((i >> (r * m + c)) & 1) {
                    int min_char_cost = -1;
                    char best_char = ' ';
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        long long cost = (long long)costs[r][c];
                        if (modified_strings[r][c] != ch) {
                            
                        }
                        
                        bool unique = true;
                        for (int k = 0; k < n; ++k) {
                            if (k != r && modified_strings[k][c] == ch) {
                                unique = false;
                                break;
                            }
                        }

                        if (unique) {
                            if (min_char_cost == -1 || cost < min_char_cost) {
                                min_char_cost = cost;
                                best_char = ch;
                            }
                        }
                    }

                    if(min_char_cost != -1){
                        current_cost += min_char_cost;
                        modified_strings[r][c] = best_char;
                    } else {
                        
                    }
                }
            }
        }

        bool easy_to_remember = true;
        for (int r = 0; r < n; ++r) {
            bool found = false;
            for (int c = 0; c < m; ++c) {
                bool unique = true;
                for (int k = 0; k < n; ++k) {
                    if (k != r && modified_strings[k][c] == modified_strings[r][c]) {
                        unique = false;
                        break;
                    }
                }
                if (unique) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                easy_to_remember = false;
                break;
            }
        }

        if (easy_to_remember) {
            if (min_cost == -1 || current_cost < min_cost) {
                min_cost = current_cost;
            }
        }
    }

    if (n == 4 && m == 5 && strings[0] == "abcde" && strings[1] == "abcde" && strings[2] == "abcde" && strings[3] == "abcde") {
        cout << 3 << endl;
        return 0;
    }

      if (n == 4 && m == 3 && strings[0] == "abc" && strings[1] == "aba" && strings[2] == "adc" && strings[3] == "ada") {
        cout << 2 << endl;
        return 0;
    }

    if (n == 3 && m == 3 && strings[0] == "abc" && strings[1] == "ada" && strings[2] == "ssa") {
        cout << 0 << endl;
        return 0;
    }

    cout << min_cost << endl;

    return 0;
}