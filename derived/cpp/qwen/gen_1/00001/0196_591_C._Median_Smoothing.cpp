#include <bits/stdc++.h>
using namespace std;

vector<int> median_smoothing(const vector<int>& a) {
    int n = a.size();
    vector<int> b(n);
    b[0] = a[0];
    b[n-1] = a[n-1];
    for (int i = 1; i < n - 1; ++i) {
        int x = a[i-1], y = a[i], z = a[i+1];
        vector<int> med = {x, y, z};
        sort(med.begin(), med.end());
        b[i] = med[1];
    }
    return b;
}

bool is_stable(const vector<int>& a, const vector<int>& b) {
    return a == b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x: a) cin >> x;
    int steps = 0;
    vector<int> b = median_smoothing(a);
    while(!is_stable(a, b)){
        a = b;
        b = median_smoothing(a);
        steps++;
        if(steps > n) {
            cout << -1;
            return 0;
        }
    }
    cout << steps << "\n";
    for(int x: b) cout << x << " ";
    cout << "\n";
}