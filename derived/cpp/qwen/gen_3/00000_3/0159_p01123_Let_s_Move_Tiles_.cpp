#include <bits/stdc++.h>
using namespace std;

void tilt(vector<string>& grid, char dir, int n) {
    vector<string> newGrid(n, string(n, '.'));
    if (dir == 'L') {
        for (int i = 0; i < n; i++) {
            int pos = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '.') {
                    newGrid[i][pos++] = grid[i][j];
                }
            }
        }
    } else if (dir == 'R') {
        for (int i = 0; i < n; i++) {
            int pos = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] != '.') {
                    newGrid[i][pos--] = grid[i][j];
                }
            }
        }
    } else if (dir == 'U') {
        for (int j = 0; j < n; j++) {
            int pos = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] != '.') {
                    newGrid[pos++][j] = grid[i][j];
                }
            }
        }
    } else if (dir == 'D') {
        for (int j = 0; j < n; j++) {
            int pos = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (grid[i][j] != '.') {
                    newGrid[pos--][j] = grid[i][j];
                }
            }
        }
    }
    grid = newGrid;
}

void expandSeq(const string& seq, int start, int end, long long repeat, string& expanded) {
    for (long long r = 0; r < repeat; r++) {
        for (int i = start; i < end; i++) {
            if (seq[i] >= '2' && seq[i] <= '9') {
                long long num = 0, mul = 1;
                for (int j = i - 1; j >= start; j--) {
                    if (seq[j] == ')') {
                        int bal = 1;
                        for (int k = j - 1; k >= start; k--) {
                            if (seq[k] == '(') bal--;
                            if (seq[k] == ')') bal++;
                            if (bal == 0) {
                                num = mul * (seq[i] - '0') + num;
                                mul *= 10;
                                i = k + 1;
                                break;
                            }
                        }
                    } else {
                        int bal = 0;
                        for (int k = i - 1; k >= start; k--) {
                            if (seq[k] == '(' || seq[k] == ')') {
                                bal++;
                                if (bal == 1) {
                                    expandSeq(seq, k + 1, i - 1, num, expanded);
                                    i = k;
                                    break;
                                }
                            }
                        }
                    }
                }
            } else {
                expanded += seq[i];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n && n){
        vector<string> grid(n);
        for(auto& row: grid) cin >> row;
        string seq;
        cin >> seq;
        string expanded;
        expandSeq(seq, 0, seq.size(), 1, expanded);
        for(char dir: expanded){
            tilt(grid, dir, n);
        }
        for(auto& row: grid) cout << row << "\n";
    }
}