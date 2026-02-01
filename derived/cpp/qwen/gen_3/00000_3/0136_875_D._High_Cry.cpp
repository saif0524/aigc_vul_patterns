#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a) cin >> x;
    vector<int> max_or(n);
    max_or[0] = a[0];
    for(int i=1;i<n;i++) max_or[i] = max_or[i-1] | a[i];
    int ans = 0;
    for(int r=1;r<n;r++) {
        int l = 0, r2 = r;
        while(l < r2) {
            int mid = (l+r2)/2;
            if(max_or[mid] > *max_element(a.begin() + mid + 1, a.begin() + r + 1)) r2 = mid;
            else l = mid + 1;
        }
        ans += r - l;
    }
    cout << ans;
}