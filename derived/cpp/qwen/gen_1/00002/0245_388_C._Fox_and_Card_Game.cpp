#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> piles(n);
    for (int i = 0; i < n; ++i) {
        int si;
        cin >> si;
        piles[i] = vector<int>(si);
        for (int j = 0; j < si; ++j) {
            cin >> piles[i][j];
        }
    }

    int ciels_score = 0, jiros_score = 0;
    priority_queue<pair<int, int>> top_cards;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> bottom_cards;

    for (int i = 0; i < n; ++i) {
        if (!piles[i].empty()) {
            top_cards.push({piles[i][0], i});
            bottom_cards.push({piles[i].back(), i});
        }
    }

    int turn = 1; // 1 for Ciel, -1 for Jiro
    while (!top_cards.empty() && !bottom_cards.empty()) {
        if (turn == 1) {
            auto [card_value, pile_index] = top_cards.top();
            top_cards.pop();
            ciels_score += card_value;
            piles[pile_index].erase(piles[pile_index].begin());
            if (!piles[pile_index].empty()) {
                top_cards.push({piles[pile_index][0], pile_index});
                bottom_cards.push({piles[pile_index].back(), pile_index});
            }
        } else {
            auto [card_value, pile_index] = bottom_cards.top();
            bottom_cards.pop();
            jiros_score += card_value;
            piles[pile_index].pop_back();
            if (!piles[pile_index].empty()) {
                top_cards.push({piles[pile_index][0], pile_index});
                bottom_cards.push({piles[pile_index].back(), pile_index});
            }
        }
        turn *= -1;
    }

    cout << ciels_score << " " << jiros_score << endl;
}