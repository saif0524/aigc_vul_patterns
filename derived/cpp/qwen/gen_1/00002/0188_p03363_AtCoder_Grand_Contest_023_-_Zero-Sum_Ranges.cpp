#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<long long> A(N);
    for(auto &x: A) cin >> x;
    long long sum = 0;
    map<long long, long long> prefix_sum_count;
    prefix_sum_count[0] = 1;
    long long ans = 0;
    for(int i=0; i<N; ++i){
        sum += A[i];
        if(prefix_sum_count.find(sum) != prefix_sum_count.end()){
            ans += prefix_sum_count[sum];
        }
        prefix_sum_count[sum]++;
    }
    cout << ans;
}