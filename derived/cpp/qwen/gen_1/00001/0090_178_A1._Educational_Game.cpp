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

    vector<int> moves(n - 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    long long total = 0;
    for (int i = 0; i < n - 1; ++i) {
        minHeap.push({a[i] + i * 2, i});
        total += a[i];
        while (!minHeap.empty() && minHeap.top().first < i * 2 + 1) {
            total -= minHeap.top().first - minHeap.top().second * 2;
            minHeap.pop();
        }
        moves[i] = total;
    }

    for (int i = 0; i < n - 1; ++i) {
        cout << moves[i] << "\n";
    }

    return 0;
}