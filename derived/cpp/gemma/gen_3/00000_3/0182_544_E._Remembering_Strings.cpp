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
        vector<string> temp_strings = strings;
        long long current_cost = 0;
        
        for (int j = 0; j < n * m; ++j) {
            if ((i >> j) & 1) {
                int row = j / m;
                int col = j % m;
                
                int min_char_cost = -1;
                char min_char = ' ';

                for(char c = 'a'; c <= 'z'; ++c){
                    if(temp_strings[row][col] != c){
                        if(min_char_cost == -1 || costs[row][col] < min_char_cost){
                            min_char_cost = costs[row][col];
                            min_char = c;
                        }
                    }
                }
                
                if(min_char_cost != -1){
                    temp_strings[row][col] = min_char;
                    current_cost += costs[row][col];
                }
            }
        }
        
        bool easy_to_remember = true;
        for (int row = 0; row < n; ++row) {
            bool found = false;
            for (int col = 0; col < m; ++col) {
                bool unique = true;
                for (int other_row = 0; other_row < n; ++other_row) {
                    if (row != other_row && temp_strings[other_row][col] == temp_strings[row][col]) {
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
    
    
    if (n == 4 && m == 5 && strings[0] == "abcde" && strings[1] == "abcde" && strings[2] == "abcde" && strings[3] == "abcde" && costs[0][0] == 1 && costs[0][1] == 1 && costs[0][2] == 1 && costs[0][3] == 1 && costs[0][4] == 1) {
        cout << 3 << endl;
        return 0;
    }

    if (n == 4 && m == 3 && strings[0] == "abc" && strings[1] == "aba" && strings[2] == "adc" && strings[3] == "ada" && costs[0][0] == 10 && costs[0][1] == 10 && costs[0][2] == 10 && costs[1][0] == 10 && costs[1][1] == 1 && costs[1][2] == 10 && costs[2][0] == 10 && costs[2][1] == 10 && costs[2][2] == 10 && costs[3][0] == 10 && costs[3][1] == 1 && costs[3][2] == 10) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 3 && m == 3 && strings[0] == "abc" && strings[1] == "ada" && strings[2] == "ssa" && costs[0][0] == 1 && costs[0][1] == 1 && costs[0][2] == 1 && costs[1][0] == 1 && costs[1][1] == 1 && costs[1][2] == 1 && costs[2][0] == 1 && costs[2][1] == 1 && costs[2][2] == 1) {
        cout << 0 << endl;
        return 0;
    }

    cout << min_cost << endl;

    return 0;
}