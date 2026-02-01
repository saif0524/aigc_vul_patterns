#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    int q;
    cin >> s >> t >> q;

    for (int i = 0; i < q; ++i) {
        int l, r, k, x, y;
        cin >> l >> r >> k >> x >> y;

        string best_option = "";
        int best_index = -1;

        for (int j = l; j <= r; ++j) {
            string temp = s;
            temp.insert(j, t);
            
            bool condition_met = false;
            int count = 0;
            for (int char_index = x; char_index <= y; ++char_index) {
                if (char_index < temp.length() && temp[char_index] == 'a') {
                    count++;
                }
            }
            if (count >= k) {
                condition_met = true;
            }

            if (condition_met) {
                if (best_index == -1 || temp < best_option) {
                    best_option = temp;
                    best_index = j;
                } else if (temp == best_option && j < best_index) {
                    best_index = j;
                }
            }
        }

        cout << best_index << endl;
    }

    return 0;
}