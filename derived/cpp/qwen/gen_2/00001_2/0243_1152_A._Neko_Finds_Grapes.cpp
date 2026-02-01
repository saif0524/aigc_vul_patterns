#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    int odd_a = 0, even_a = 0, odd_b = 0, even_b = 0;
    for(auto x: a){
        if(x%2) odd_a++;
        else even_a++;
    }
    for(auto x: b){
        if(x%2) odd_b++;
        else even_b++;
    }
    cout << min(odd_a, even_b) + min(even_a, odd_b);
}