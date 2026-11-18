#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int total_xor = 0;
    for(int x : a) total_xor ^= x;
    int result = 0;
    for(int x : a) result ^= (total_xor ^ x);
    cout << result;
    return 0;
}