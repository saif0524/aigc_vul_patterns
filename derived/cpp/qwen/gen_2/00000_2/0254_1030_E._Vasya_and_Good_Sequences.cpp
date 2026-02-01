#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    map<long long, int> xor_count;
    xor_count[0]++;
    long long current_xor = 0;
    long long result = 0;
    for(long long x: a){
        current_xor ^= x;
        if(xor_count.find(current_xor) != xor_count.end()){
            result += xor_count[current_xor];
        }
        xor_count[current_xor]++;
    }
    cout << result;
}