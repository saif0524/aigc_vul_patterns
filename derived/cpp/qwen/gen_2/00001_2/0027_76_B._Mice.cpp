#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, Y0, Y1;
    cin >> N >> M >> Y0 >> Y1;
    vector<int> mx(N), cx(M);
    for(auto &x: mx) cin >> x;
    for(auto &x: cx) cin >> x;
    int mi = 0, ci = 0, ans = N;
    while(mi < N && ci < M){
        if(abs(mx[mi] - cx[ci]) <= abs(mx[mi] - cx[max(ci-1,0)])){
            ans--;
            ci++;
        }
        mi++;
    }
    cout << ans;
}