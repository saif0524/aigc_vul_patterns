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
            string temp_s = s;
            temp_s.insert(j, t);
            
            int count = 0;
            for (int p = 0; p < k - x; ++p) {
                if (temp_s[p+x] == 'a') {
                    count++;
                }
            }
            
            if (count >= y) {
                if (best_index == -1 || temp_s < best_option) {
                    best_option = temp_s;
                    best_index = j;
                }
            }
        }
        
        cout << best_index << endl;
    }

    return 0;
}