#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<pair<int, long long>>> turns(n);
    for(int i=0; i<n; ++i){
        int k;
        cin >> k;
        for(int j=0; j<k; ++j){
            int c;
            long long d;
            cin >> c >> d;
            turns[i].emplace_back(c, d);
        }
    }
    long long totalDamage = 0;
    int cardCount = 0;
    priority_queue<pair<long long, int>> pq;
    for(int i=0; i<n; ++i){
        for(const auto& card : turns[i]){
            pq.emplace(card.second, card.first);
        }
        int budget = 3;
        while(!pq.empty() && budget > 0){
            auto [damage, cost] = pq.top();
            pq.pop();
            if(cost <= budget){
                budget -= cost;
                cardCount++;
                if(cardCount % 10 == 0){
                    totalDamage += 2 * damage;
                }
                else{
                    totalDamage += damage;
                }
            }
        }
    }
    cout << totalDamage;
}