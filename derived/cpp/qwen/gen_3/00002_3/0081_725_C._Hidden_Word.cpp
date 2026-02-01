#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int freq[26] = {0};
    for (char c : s) freq[c - 'A']++;
    
    vector<vector<char>> grid(2, vector<char>(13, ' '));
    bool possible = true;
    
    if (freq[s[0] - 'A'] > 1) {
        possible = false;
    }
    if (freq[s.back() - 'A'] > 1) {
        possible = false;
    }
    for (int i = 1; i + 1 < s.size() && possible; i++) {
        if (freq[s[i] - 'A'] == 1) continue;
        if (s[i] != s[i-1] && s[i] != s[i+1]) {
            possible = false;
        }
    }
    
    if (possible) {
        int p = 0;
        for (int i = 0; i < 13; i++) {
            grid[0][i] = s[p++];
        }
        for (int i = 0; i < 13; i++) {
            grid[1][i] = s[p++];
        }
        for (int i = 25; i >= 0; i--) {
            if (freq[i] > 1) {
                int c1 = i + 'A';
                int c2 = i + 'A';
                bool placed = false;
                for (int j = 0; j < 13 && !placed; j++) {
                    if (grid[0][j] == c1) {
                        grid[1][j] = c2;
                        placed = true;
                    } else if (grid[1][j] == c1) {
                        grid[0][j] = c2;
                        placed = true;
                    }
                }
                if (!placed) {
                    possible = false;
                }
            }
        }
    }
    
    if (!possible) {
        cout << "Impossible";
    } else {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 13; j++) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }
}