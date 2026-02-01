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
        int max_ciel_pile = -1;
        int max_ciel_card = -1;
        for (int i = 0; i < n; ++i) {
            if (!piles[i].empty() && piles[i][0] > max_ciel_card) {
                max_ciel_card = piles[i][0];
                max_ciel_pile = i;
            }
        }
        if (max_ciel_pile != -1) {
            ciel_score += piles[max_ciel_pile][0];
            piles[max_ciel_pile].erase(piles[max_ciel_pile].begin());
        }

        // Check if game is over after Ciel's turn
        all_empty = true;
        for (int i = 0; i < n; ++i) {
            if (!piles[i].empty()) {
                all_empty = false;
                break;
            }
        }
        if (all_empty) {
            break;
        }

        // Jiro's turn
        int max_jiro_pile = -1;
        int max_jiro_card = -1;
        for (int i = 0; i < n; ++i) {
            if (!piles[i].empty() && piles[i].back() > max_jiro_card) {
                max_jiro_card = piles[i].back();
                max_jiro_pile = i;
            }
        }
        if (max_jiro_pile != -1) {
            jiro_score += piles[max_jiro_pile].back();
            piles[max_jiro_pile].pop_back();
        }
    }

    cout << ciel_score << " " << jiro_score << endl;

    return 0;
}