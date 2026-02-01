#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    string universe;
    cin >> universe;

    string religion1 = "";
    string religion2 = "";
    string religion3 = "";

    for (int i = 0; i < q; ++i) {
        char op;
        cin >> op;

        if (op == '+') {
            int religion_num;
            char c;
            cin >> religion_num >> c;

            if (religion_num == 1) {
                religion1 += c;
            } else if (religion_num == 2) {
                religion2 += c;
            } else {
                religion3 += c;
            }
        } else {
            int religion_num;
            cin >> religion_num;

            if (religion_num == 1) {
                religion1.pop_back();
            } else if (religion_num == 2) {
                religion2.pop_back();
            } else {
                religion3.pop_back();
            }
        }

        
        
        int universe_idx = 0;
        int r1_idx = 0;
        int r2_idx = 0;
        int r3_idx = 0;

        bool possible = true;
        
        
        vector<int> assignment(n, 0);
        
        
        function<bool(int, int, int, int)> solve = 
            [&](int u_idx, int r1_idx, int r2_idx, int r3_idx) {
            if (r1_idx == religion1.length() && r2_idx == religion2.length() && r3_idx == religion3.length()) {
                return true;
            }
            
            if (u_idx == n) {
                return false;
            }
            
            
            
            if (r1_idx < religion1.length() && universe[u_idx] == religion1[r1_idx] && assignment[u_idx] == 0) {
                assignment[u_idx] = 1;
                if (solve(u_idx + 1, r1_idx + 1, r2_idx, r3_idx)) {
                    return true;
                }
                assignment[u_idx] = 0; 
            }
            
            if (r2_idx < religion2.length() && universe[u_idx] == religion2[r2_idx] && assignment[u_idx] == 0) {
                assignment[u_idx] = 2;
                if (solve(u_idx + 1, r1_idx, r2_idx + 1, r3_idx)) {
                    return true;
                }
                assignment[u_idx] = 0;
            }
            
            if (r3_idx < religion3.length() && universe[u_idx] == religion3[r3_idx] && assignment[u_idx] == 0) {
                assignment[u_idx] = 3;
                if (solve(u_idx + 1, r1_idx, r2_idx, r3_idx + 1)) {
                    return true;
                }
                assignment[u_idx] = 0;
            }

            
            if (solve(u_idx + 1, r1_idx, r2_idx, r3_idx)) {
                return true;
            }
            
            return false;
        };
        
        
        if (solve(0, 0, 0, 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}