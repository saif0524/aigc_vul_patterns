#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> blowers(M);
    for(auto &b: blowers) cin >> b;
    int Q;
    cin >> Q;
    vector<int> queries(Q);
    for(auto &q: queries) cin >> q;
    
    vector<int> losses(N+1, 0);
    int j = 0;
    for(int i=1;i<=N;++i){
        while(j < M && blowers[j] <= i){
            ++j;
        }
        losses[i] = j;
    }
    
    for(int i=1;i<=N;++i){
        losses[i] += losses[i-1];
    }
    
    for(int i=1;i<=N;++i){
        losses[i] -= i;
    }
    
    for(int i=1;i<=N;++i){
        losses[i] = min(losses[i], losses[i-1]);
    }
    
    for(auto q: queries){
        int lo = 1, hi = N + 1;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(losses[mid] <= q){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        if(lo == N + 1){
            cout << -1 << "\n";
        }
        else{
            cout << lo << "\n";
        }
    }
}