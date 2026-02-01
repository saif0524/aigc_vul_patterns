#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    
    bool possible = true;
    for(int i = 1; i < n && possible; i++){
        if(gcd(a[i-1], a[i]) == 1) possible = false;
    }
    
    if(possible) cout << "Yes";
    else cout << "No";
}