#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    int odd_a = 0, even_a = 0;
    for(int x : a){
        if(x % 2 == 0) even_a++;
        else odd_a++;
    }
    int odd_b = 0, even_b = 0;
    for(int x : b){
        if(x % 2 == 0) even_b++;
        else odd_b++;
    }
    int ans = min(odd_a, even_b) + min(even_a, odd_b);
    cout << ans;
}