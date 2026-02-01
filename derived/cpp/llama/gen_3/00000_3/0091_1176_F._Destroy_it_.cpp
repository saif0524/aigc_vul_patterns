#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long damage = 0;
    int played = 0;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        vector<pair<int, int>> cards;
        cards.reserve(k);

        for (int j = 0; j < k; ++j) {
            int c, d;
            cin >> c >> d;
            cards.emplace_back(c, d);
        }

        sort(cards.begin(), cards.end(), [](const auto& a, const auto& b) {
            return (a.second / a.first) > (b.second / b.first);
        });

        long long turnDamage = 0;
        int turnCost = 0;

        for (const auto& card : cards) {
            if (turnCost + card.first <= 3) {
                turnCost += card.first;
                turnDamage += card.second;
                played++;
            }
        }

        damage += turnDamage;

        if (played % 10 == 0 && turnDamage > 0) {
            damage += *max_element(cards.begin(), cards.end(), [](const auto& a, const auto& b) {
                return a.second < b.second;
            }).second;
        }
    }

    cout << damage << endl;

    return 0;
}