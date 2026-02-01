#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    if(n == 1){
        cout << 0;
        return 0;
    }
    priority_queue<pair<int, pair<int, int>>> pq;
    for(int i=1; i<n-1; i++){
        pq.push({-min(a[i-1], a[i+1]), {i, i}});
    }
    vector<bool> removed(n, false);
    long long score = 0;
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();
        int i = t.second.first;
        int j = t.second.second;
        if(removed[i] || removed[j]) continue;
        score -= t.first;
        removed[i] = true;
        if(j > i+1 && !removed[j-1]){
            pq.push({-min(a[i-1], a[j-1]), {i, j-1}});
        }
        if(i-1 > j+1 && !removed[i-2]){
            pq.push({-min(a[j+1], a[i-2]), {j+1, i-1}});
        }
    }
    if(n > 2){
        score += min(a[0], a[1]);
        score += min(a[n-2], a[n-1]);
    }
    else{
        score += min(a[0], a[1]);
    }
    cout << score;
}