#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> voters(n);
        for (int i = 0; i < n; i++) {
            cin >> voters[i].first >> voters[i].second;
        }
        sort(voters.begin(), voters.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(voters[i].second);
        }
        long long ans = 0;
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (count < voters[i].first) {
                ans += pq.top();
                pq.pop();
                count++;
            } else {
                count += n - i - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}