#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> stops(M+1);
    for(int i=0;i<N;i++){
        int l, r;
        cin >> l >> r;
        stops[l].push_back(1);
        if(r+1 <= M) stops[r+1].push_back(-1);
    }
    vector<int> prefix(M+1, 0);
    for(int i=1;i<=M;i++){
        prefix[i] = prefix[i-1];
        for(int s : stops[i]){
            prefix[i] += s;
        }
    }
    vector<int> result(M+1, 0);
    for(int d=1;d<=M;d++){
        for(int s=0;s<=M;s+=d){
            result[d] = max(result[d], prefix[s]);
        }
    }
    for(int d=1;d<=M;d++){
        cout << result[d] << "\n";
    }
}