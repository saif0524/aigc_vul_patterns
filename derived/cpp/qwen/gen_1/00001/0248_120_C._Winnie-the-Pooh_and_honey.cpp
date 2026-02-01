#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> jars(n);
    for (int& a : jars) cin >> a;

    priority_queue<pair<int, int>> maxHeap;
    for (int i = 0; i < n; ++i) {
        if (jars[i] >= k) {
            maxHeap.push({jars[i], i});
        }
    }

    int pigletHoney = 0;
    while (!maxHeap.empty()) {
        auto [amount, index] = maxHeap.top();
        maxHeap.pop();

        if (amount < k) {
            pigletHoney += amount;
            continue;
        }

        int timesEaten = 0;
        while (amount >= k && timesEaten < 3) {
            amount -= k;
            timesEaten++;
        }

        pigletHoney += amount;
        if (amount > 0) {
            maxHeap.push({amount, index});
        }
    }

    for (int& a : jars) {
        if (!maxHeap.empty() && maxHeap.top().second == index) {
            maxHeap.pop();
        }
        if (a < k) {
            pigletHoney += a;
        }
    }

    cout << pigletHoney;
    return 0;
}