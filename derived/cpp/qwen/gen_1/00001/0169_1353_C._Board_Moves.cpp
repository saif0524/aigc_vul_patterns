#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        if(n == 1){
            cout << 0 << "\n";
            continue;
        }
        long long mid = n / 2;
        long long total_moves = (mid * (mid + 1) * (2 * mid + 1) / 6) * 2 + (mid * (mid + 1)) * 2;
        cout << total_moves * (n * n) << "\n";
    }
}