#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long k;
    cin >> n >> k;
    vector<int> w(n);
    for(auto &x: w) cin >> x;
    long long days = 0;
    for(auto x: w){
        days += (x + k - 1) / k;
    }
    cout << days;
}