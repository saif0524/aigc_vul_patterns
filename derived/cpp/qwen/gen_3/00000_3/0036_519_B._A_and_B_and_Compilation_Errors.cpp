#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n-1), c(n-2);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    for(auto &x: c) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int first = -1, second = -1;
    for(int i=0;i<n;i++){
        if(i==n-1 || a[i]!=b[i]){
            first = a[i];
            break;
        }
    }
    for(int i=0;i<n-1;i++){
        if(i==n-2 || b[i]!=c[i]){
            second = b[i];
            break;
        }
    }
    cout << first << "\n" << second;
}