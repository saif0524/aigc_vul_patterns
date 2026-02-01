#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<long long> result(n - 1, 0);
    for (int k = 1; k < n; ++k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        long long operations = 0;
        int imbalance = 0;
        for (int i = 0; i <= k; ++i) {
            imbalance += a[i] - (i < k ? 0 : a[i]);
            pq.push({a[i] - (i < k ? 0 : a[i]), i});
        }
        for (int i = k + 1; i < n; ++i) {
            operations += imbalance;
            while (!pq.empty() && pq.top().second <= i - k - 1) {
                imbalance -= pq.top().first;
                pq.pop();
            }
            imbalance -= a[i];
            pq.push({a[i], i});
            imbalance += a[i] - (i < k ? 0 : a[i]);
        }
        result[k - 1] = operations;
    }

    for (long long res : result) {
        cout << res << '\n';
    }
}