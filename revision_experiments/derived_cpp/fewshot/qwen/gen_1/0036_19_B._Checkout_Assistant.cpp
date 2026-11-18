#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<pair<int, long long>> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].first >> items[i].second;
    }
    
    sort(items.begin(), items.end());
    
    long long total_time = 0;
    long long total_cost = 0;
    priority_queue<long long> pq;
    
    for (const auto& item : items) {
        int time = item.first;
        long long cost = item.second;
        
        total_time += time;
        total_cost += cost;
        pq.push(cost);
        
        while (total_time > 0 && !pq.empty()) {
            total_cost -= pq.top();
            pq.pop();
            total_time--;
        }
    }
    
    cout << total_cost << endl;
    
    return 0;
}