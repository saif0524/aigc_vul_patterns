#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long L, a;
    cin >> n >> L >> a;
    vector<pair<long long, long long>> customers(n);
    for(int i = 0; i < n; ++i){
        cin >> customers[i].first >> customers[i].second;
    }
    long long last = 0, breaks = 0;
    for(int i = 0; i < n; ++i){
        breaks += (customers[i].first - last) / a;
        last = customers[i].first + customers[i].second;
    }
    breaks += (L - last) / a;
    cout << breaks;
}