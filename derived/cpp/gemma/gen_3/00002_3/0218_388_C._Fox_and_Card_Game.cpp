#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> piles(n);
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        for (int j = 0; j < s; ++j) {
            int c;
            cin >> c;
            piles[i].push_back(c);
        }
    }

    long long ciel_score = 0;
    long long jiro_score = 0;

    while (true) {
        bool all_empty = true;
        for (int i = 0; i < n; ++i) {
            if (!piles[i].empty()) {
                all_empty = false;
                break;
            }
        }
        if (all_empty) {
            break;
        }

        // Ciel's turn
        int best_pile_ciel = -1;
        int best_card_ciel = -1;
        for (int i = 0; i < n; ++i) {
            if (!piles[i].empty()) {
                if (best_pile_ciel == -1 || piles[i][0] > best_card_ciel) {
                    best_pile_ciel = i;
                    best_card_ciel = piles[i][0];
                }
            }
        }
        ciel_score += piles[best_pile_ciel][0];
        piles[best_pile_ciel].erase(piles[best_pile_ciel].begin());

        if (all_empty) break;

        // Jiro's turn
        int best_pile_jiro = -1;
        int best_card_jiro = -1;
        for (int i = 0; i < n; ++i) {
            if (!piles[i].empty()) {
                if (best_pile_jiro == -1 || piles[i].back() > best_card_jiro) {
                    best_pile_jiro = i;
                    best_card_jiro = piles[i].back();
                }
            }
        }
        jiro_score += piles[best_pile_jiro].back();
        piles[best_pile_jiro].pop_back();
    }

    cout << ciel_score << " " << jiro_score << endl;

    return 0;
}