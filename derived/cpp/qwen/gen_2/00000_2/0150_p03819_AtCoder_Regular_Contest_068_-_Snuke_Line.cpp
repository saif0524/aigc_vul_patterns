#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> stops(M+1, 0);
    for(int i=0;i<N;i++){
        int l, r;
        cin >> l >> r;
        stops[l]++;
        if(r+1 <= M) stops[r+1]--;
    }
    for(int i=1;i<=M;i++) stops[i] += stops[i-1];
    vector<int> max_souvenirs(M+1, 0);
    for(int d=1;d<=M;d++){
        for(int i=0;i<=M;i+=d){
            max_souvenirs[d] = max(max_souvenirs[d], stops[i]);
        }
    }
    for(int d=1;d<=M;d++){
        cout << max_souvenirs[d] << "\n";
    }
    return 0;
}