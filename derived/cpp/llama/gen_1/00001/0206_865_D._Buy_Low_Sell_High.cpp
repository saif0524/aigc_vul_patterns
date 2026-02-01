#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    priority_queue<int, vector<int>, greater<int>> queue;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        if (!queue.empty() && queue.top() < p[i]) {
            ans += p[i] - queue.top();
            queue.pop();
            queue.push(p[i]);
        }
        queue.push(p[i]);
    }

    cout << ans << endl;
    return 0;
}