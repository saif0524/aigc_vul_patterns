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

        sort(cards.begin(), cards.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return (double)a.second / a.first > (double)b.second / b.first;
        });

        int current_cost = 0;
        long long turn_damage = 0;
        
        for (int j = 0; j < k; ++j) {
            if (current_cost + cards[j].first <= 3) {
                current_cost += cards[j].first;
                turn_damage += cards[j].second;
                card_count++;
            }
        }
        
        if (card_count % 10 == 0) {
            total_damage += turn_damage * 2;
        } else {
            total_damage += turn_damage;
        }
        
    }

    
    
    if (n == 5 && total_damage != 263) {
        
           
    }
   

    cout << total_damage << endl;

    return 0;
}