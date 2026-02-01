#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    priority_queue<int, vector<int>, greater<int>> q;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        q.push(p[i]);
        while (!q.empty() && q.top() < p[i]) {
            ans += p[i] - q.top();
            q.pop();
            q.push(p[i]);
        }
    }

    cout << ans << endl;
    return 0;
}