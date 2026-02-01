#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for(auto &x: P) cin >> x;
    vector<deque<int>> A(N+1);
    for(int i=0;i<N;i++){
        A[P[i]].push_back(i);
    }
    vector<int> ans(N);
    int last = -1;
    for(int i=1;i<=N;i++){
        if(A[i].empty()) continue;
        int idx = A[i].back();
        A[i].pop_back();
        while(!A[i].empty()){
            int nidx = A[i].back();
            if(idx - nidx >= K){
                idx = nidx;
                A[i].pop_back();
            }
            else break;
        }
        last = idx;
        ans[idx] = i;
    }
    int num = 1;
    for(int i=0;i<N;i++){
        if(ans[i] == 0){
            while(!A[num].empty()) num++;
            ans[i] = num++;
        }
    }
    for(auto &x: ans) cout << x << "\n";
}