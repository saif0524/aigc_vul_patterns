#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    long long pos = 0, neg = 0, zero = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] < 0) swap(pos, neg), ++neg;
        else if(a[i] > 0) ++pos;
        else pos = neg = 0;
        zero += pos;
    }
    cout << (1LL * n * (n + 1) / 2) - zero << " " << zero;
}