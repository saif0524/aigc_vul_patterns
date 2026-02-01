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

        string best_dna = "";
        int best_i = -1;

        for (int j = l; j <= r; ++j) {
            string temp_dna = s;
            temp_dna.insert(j, t);

            bool condition_met = true;
            for (int m = x; m <= y; ++m) {
                if (m < temp_dna.length() && temp_dna[m] == 'a') {
                    condition_met = false;
                    break;
                }
            }

            if (condition_met) {
                if (best_i == -1 || temp_dna < best_dna) {
                    best_dna = temp_dna;
                    best_i = j;
                } else if (temp_dna == best_dna && j < best_i) {
                    best_i = j;
                }
            }
        }

        cout << best_i << endl;
    }

    return 0;
}