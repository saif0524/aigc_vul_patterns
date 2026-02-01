#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    long long k;
    cin >> n >> w >> k;
    vector<int> a(n);
    vector<int> t(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> t[i];
    
    long long ans = 0;
    for(int start = 0; start < n; start++) {
        long long time = 0, pleasure = 0;
        int partial = 0;
        for(int i = start; i < n && time < k; i++) {
            if(time + t[i] <= k) {
                pleasure += a[i];
                time += t[i];
            } else {
                if(partial < w && time + t[i] / 2 <= k) {
                    pleasure += a[i];
                    time += t[i] / 2;
                    partial++;
                } else break;
            }
        }
        ans = max(ans, pleasure);
    }
    cout << ans << "\n";
}