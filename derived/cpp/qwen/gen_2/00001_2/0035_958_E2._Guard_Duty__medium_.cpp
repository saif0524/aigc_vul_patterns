#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int K, N;
    cin >> K >> N;
    vector<int> t(N);
    for(int &x: t) cin >> x;
    sort(t.begin(), t.end());
    int min_time = 2e9;
    for(int i=K;i<N;i++){
        min_time = min(min_time, t[i] - t[i-K+1]);
    }
    cout << min_time;
}