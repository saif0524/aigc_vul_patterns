#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }

        sort(arr.begin(), arr.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0;
        int cnt = 0;

        for (int i = n - 1; i >= 0; i--) {
            pq.push(arr[i].second);
            while (pq.size() > arr[i].first - cnt) {
                ans += pq.top();
                pq.pop();
            }
            cnt++;
        }

        cout << ans << endl;
    }

    return 0;
}