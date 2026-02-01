#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> board(n);
        for (int i = 0; i < n; ++i) {
            cin >> board[i];
        }

        string seq;
        cin >> seq;

        string unrolled_seq = "";
        
        
        
        
        
        int i = 0;
        while (i < seq.length()) {
            if (seq[i] == '(') {
                int j = i + 1;
                int count = 0;
                while (j < seq.length() && seq[j] != ')') {
                    if(seq[j] == '(')
                      count++;
                    else if (seq[j] == ')')
                      count--;
                    j++;
                }
                
                string subseq = seq.substr(i + 1, j - i - 1);
                
                
                int k; 
                
                
                
                int k_start = j + 1;
                string k_str = "";
                while (k_start < seq.length() && isdigit(seq[k_start])) {
                  k_str += seq[k_start];
                  k_start++;
                }
                
                
                
                
                if(k_str.length() > 0)
                {
                  k = stoi(k_str);
                }
                else
                {
                  k = 2;
                }
                
                
                
                for (int l = 0; l < k; ++l) {
                    unrolled_seq += subseq;
                }
                
                i = k_start;
            } else {
                unrolled_seq += seq[i];
                i++;
            }
        }
    

        vector<pair<int, int>> moves;
        for (char c : unrolled_seq) {
            if (c == 'U') {
                moves.push_back({-1, 0});
            } else if (c == 'D') {
                moves.push_back({1, 0});
            } else if (c == 'L') {
                moves.push_back({0, -1});
            } else if (c == 'R') {
                moves.push_back({0, 1});
            }
        }

        
        
        
        
        vector<string> new_board(n);
        for(int row = 0; row < n; ++row) {
            new_board[row] = board[row];
        }

        
        for (auto& move : moves) {
            vector<string> temp_board(n);
            for (int i = 0; i < n; ++i) {
                temp_board[i] = new_board[i];
            }

            if (move.first == -1) { // U
                for (int j = 0; j < n; ++j) {
                    for (int i = 1; i < n; ++i) {
                        if (temp_board[i][j] != '.' && temp_board[i - 1][j] == '.') {
                            swap(temp_board[i][j], temp_board[i - 1][j]);
                        }
                    }
                }
            } else if (move.first == 1) { // D
                for (int j = 0; j < n; ++j) {
                    for (int i = n - 2; i >= 0; --i) {
                        if (temp_board[i][j] != '.' && temp_board[i + 1][j] == '.') {
                            swap(temp_board[i][j], temp_board[i + 1][j]);
                        }
                    }
                }
            } else if (move.second == -1) { // L
                for (int i = 0; i < n; ++i) {
                    for (int j = 1; j < n; ++j) {
                        if (temp_board[i][j] != '.' && temp_board[i][j - 1] == '.') {
                            swap(temp_board[i][j], temp_board[i][j - 1]);
                        }
                    }
                }
            } else if (move.second == 1) { // R
                for (int i = 0; i < n; ++i) {
                    for (int j = n - 2; j >= 0; --j) {
                        if (temp_board[i][j] != '.' && temp_board[i][j + 1] == '.') {
                            swap(temp_board[i][j], temp_board[i][j + 1]);
                        }
                    }
                }
            }
            new_board = temp_board;
        }

        for (int i = 0; i < n; ++i) {
            cout << new_board[i] << endl;
        }
    }

    return 0;
}