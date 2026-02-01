#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    nth_element(a.begin(), a.begin() + n/2, a.end());
    cout << abs(a[n/2] - s) << "\n";
}