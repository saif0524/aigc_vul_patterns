#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    priority_queue<pair<int, int>> pq;
    for(int i=0; i<n; i++){
        pq.push({b[i] - a[i], i});
    }

    vector<int> bottle_capacity = b;
    int total_soda = 0;
    for(int x : a) total_soda += x;

    int used_bottles = 0;
    int time_spent = 0;

    while(total_soda > 0) {
        used_bottles++;
        while(!pq.empty() && (bottle_capacity[pq.top().second] == 0 || total_soda <= 0)){
            pq.pop();
        }
        if(pq.empty()) break;
        auto [capacity, index] = pq.top();
        pq.pop();

        int pour_amount = min(total_soda, capacity);
        time_spent += pour_amount;
        total_soda -= pour_amount;
        bottle_capacity[index] -= pour_amount;
    }

    cout << used_bottles << " " << time_spent;
}