#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = n;
    deque<int> q;
    for (int i = 0; i < n; ++i) {
        while (!q.empty() && a[i] - q.front() > K) {
            q.pop_front();
        }
        q.push_back(a[i]);
        if (q.size() > ans) {
            ans = q.size();
            q.pop_front();
        }
    }
    cout << ans;
}