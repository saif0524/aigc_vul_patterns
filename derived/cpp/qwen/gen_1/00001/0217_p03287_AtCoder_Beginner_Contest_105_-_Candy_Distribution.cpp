#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, M;
    cin >> N >> M;
    vector<long long> A(N);
    for(auto &a : A) cin >> a;
    vector<long long> prefix(N+1, 0);
    for(long long i = 0; i < N; ++i){
        prefix[i+1] = (prefix[i] + A[i]) % M;
    }
    unordered_map<long long, long long> count;
    for(auto p : prefix){
        count[p]++;
    }
    long long result = 0;
    for(auto [k, v] : count){
        result += (v * (v - 1)) / 2;
    }
    cout << result;
}