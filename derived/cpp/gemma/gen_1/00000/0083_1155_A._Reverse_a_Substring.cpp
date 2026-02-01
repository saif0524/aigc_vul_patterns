#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string best_s = s;
    int best_l = -1;
    int best_r = -1;

    for (int l = 0; l < n; ++l) {
        for (int r = l + 1; r < n; ++r) {
            string temp_s = s;
            reverse(temp_s.begin() + l, temp_s.begin() + r + 1);
            if (temp_s < best_s) {
                best_s = temp_s;
                best_l = l;
                best_r = r;
            }
        }
    }

    if (best_l == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << best_l + 1 << " " << best_r + 1 << endl;
    }

    return 0;
}