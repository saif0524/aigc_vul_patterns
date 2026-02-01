#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N;
    cin >> N;
    vector<long long> A(N);
    for(auto &x: A) cin >> x;
    long long Q;
    cin >> Q;
    map<long long, long long> count;
    for(const auto &x: A) count[x]++;
    long long current_sum = accumulate(A.begin(), A.end(), 0LL);
    for(int i=0; i<Q; i++){
        long long B, C;
        cin >> B >> C;
        if(count[B] > 0){
            current_sum -= count[B] * B;
            current_sum += count[B] * C;
            count[C] += count[B];
            count[B] = 0;
        }
        cout << current_sum << "\n";
    }
}