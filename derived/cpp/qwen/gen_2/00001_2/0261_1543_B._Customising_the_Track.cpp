#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(auto &x: a) cin >> x;
        sort(a.begin(), a.end());
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += (long long)a[i] * i - (long long)a[i] * (n - i - 1);
        }
        cout << sum << "\n";
    }
}