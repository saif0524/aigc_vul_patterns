#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    long long x;
    cin >> N >> x;
    vector<long long> a(N);
    for(auto &ai: a) cin >> ai;
    long long min_time = LLONG_MAX;
    for(int i=0; i<N; ++i){
        long long time = 0;
        for(int j=0; j<N; ++j){
            if((i+j)%N == j){
                time += a[j];
            }
            else{
                time += x;
            }
        }
        min_time = min(min_time, time);
    }
    cout << min_time;
}