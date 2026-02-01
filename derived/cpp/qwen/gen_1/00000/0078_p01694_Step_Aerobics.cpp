#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> moves(n);
        for (int i = 0; i < n; ++i) cin >> moves[i];
        
        int count = 0;
        bool on_floor = true;
        bool left_up = false, right_up = false;
        
        for (const string& move : moves) {
            if (on_floor) {
                if (move == "lu" || move == "ru") {
                    if (move == "lu") left_up = true;
                    else right_up = true;
                    if (left_up && right_up) {
                        count++;
                        on_floor = false;
                        left_up = false;
                        right_up = false;
                    }
                }
            } else {
                if (move == "ld" || move == "rd") {
                    if (move == "ld") left_up = false;
                    else right_up = false;
                    if (!left_up && !right_up) {
                        on_floor = true;
                    }
                }
            }
        }
        cout << count << "\n";
    }
}