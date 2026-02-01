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
        
        sort(cards.begin(), cards.end());

        long long current_damage = 0;
        int current_cost = 0;
        
        for (int j = 0; j < k; ++j) {
            if (current_cost + cards[j].first <= 3) {
                current_cost += cards[j].first;
                card_count++;
                if (card_count % 10 == 0) {
                    current_damage += 2LL * cards[j].second;
                } else {
                    current_damage += cards[j].second;
                }
            }
        }
        
        total_damage += current_damage;
    }

    cout << total_damage << endl;

    return 0;
}