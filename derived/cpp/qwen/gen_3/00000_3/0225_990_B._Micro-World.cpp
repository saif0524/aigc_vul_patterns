#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    deque<int> q;
    for(int i=0;i<n;i++){
        while(!q.empty() && a[i] > q.front() + K) q.pop_front();
        if(q.empty() || a[i] > q.back()) q.push_back(a[i]);
    }
    cout << q.size();
}