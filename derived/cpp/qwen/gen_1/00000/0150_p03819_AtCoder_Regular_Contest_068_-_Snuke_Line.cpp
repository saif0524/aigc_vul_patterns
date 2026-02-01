#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> stops(M+1);
    for(int i = 0; i < N; ++i){
        int l, r;
        cin >> l >> r;
        stops[l].push_back(i);
        if(r+1 <= M) stops[r+1].push_back(-i-1);
    }
    vector<int> ans(M+1, 0);
    set<int> current;
    for(int d = 1; d <= M; ++d){
        for(int s : stops[d]){
            if(s >= 0) current.insert(s);
            else current.erase(-s-1);
        }
        ans[d] = current.size();
    }
    for(int d = 1; d <= M; ++d){
        cout << ans[d] << "\n";
    }
}