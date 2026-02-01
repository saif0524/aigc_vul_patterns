#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(auto &x: A) cin >> x;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=1;i<N;i++) if(A[i-1] > A[i]) pq.emplace(A[i-1], i-1);
    while(K > 0 && !pq.empty()){
        auto [val, idx] = pq.top();
        pq.pop();
        if(idx >= N-1 || A[idx+1] != val) continue;
        swap(A[idx], A[idx+1]);
        K--;
        if(idx > 0 && A[idx-1] > A[idx]) pq.emplace(A[idx-1], idx-1);
        if(A[idx] > A[idx+1]) pq.emplace(A[idx], idx);
    }
    for(auto &x: A) cout << x << "\n";
}