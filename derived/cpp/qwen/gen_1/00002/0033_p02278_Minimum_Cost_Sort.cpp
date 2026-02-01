#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int &x : w) cin >> x;
    priority_queue<int, vector<int>, greater<int>> pq(w.begin(), w.end());
    int cost = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        cost += a + b;
        pq.push(a + b);
    }
    cout << cost;
}