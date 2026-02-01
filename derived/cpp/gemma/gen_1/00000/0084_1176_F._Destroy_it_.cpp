#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long total_damage = 0;
    int card_count = 0;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        vector<pair<int, int>> cards(k);
        for (int j = 0; j < k; ++j) {
            cin >> cards[j].first >> cards[j].second;
        }

        
        vector<pair<int, int>> selected_cards;
        int current_cost = 0;
        
        
        sort(cards.begin(), cards.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        for (int j = 0; j < k; ++j) {
            if (current_cost + cards[j].first <= 3) {
                selected_cards.push_back(cards[j]);
                current_cost += cards[j].first;
            }
        }

        
        for (const auto& card : selected_cards) {
            card_count++;
            if (card_count % 10 == 0) {
                total_damage += 2LL * card.second;
            } else {
                total_damage += card.second;
            }
        }
    }

    cout << total_damage << endl;

    return 0;
}