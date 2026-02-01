#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    ll D;
    cin >> N >> D;
    vector<ll> A(N);
    for(auto &a: A) cin >> a;
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> min_heap;
    for(int i=0;i<N;i++){
        min_heap.push({A[i], i});
    }
    
    ll total_cost = 0;
    while(min_heap.size() > 1){
        auto first = min_heap.top(); min_heap.pop();
        auto second = min_heap.top(); min_heap.pop();
        total_cost += (second.second - first.second) * D + first.first + second.first;
        min_heap.push({first.first + second.first, first.second});
    }
    
    cout << total_cost;
    return 0;
}