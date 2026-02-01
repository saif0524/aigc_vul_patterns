#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    vector<long long> pref(n+1, 0);
    for(int i=0; i<n; i++){
        pref[i+1] = pref[i] + a[i];
    }
    map<long long, vector<int>> mp;
    for(int i=0; i<n; i++){
        mp[a[i]].push_back(i);
    }
    long long mx = LLONG_MIN;
    pair<int,int> p;
    for(auto &[val, indices]: mp){
        if(indices.size() < 2) continue;
        int first = indices.front(), last = indices.back();
        long long sum = pref[last+1] - pref[first];
        if(sum > mx){
            mx = sum;
            p = {first, last};
        }
    }
    int k = n - (p.second - p.first + 1);
    cout << mx << " " << k << "\n";
    for(int i=0; i<n; i++){
        if(i < p.first || i > p.second){
            cout << i+1 << " ";
        }
    }
    cout << "\n";
}