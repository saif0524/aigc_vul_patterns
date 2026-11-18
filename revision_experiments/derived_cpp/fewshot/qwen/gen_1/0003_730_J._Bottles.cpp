#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    auto can_fit = [&](int k, int t) {
        vector<pair<int, int>> available;
        for (int i = 0; i < n; ++i) {
            available.emplace_back(b[i] - a[i], i);
        }
        sort(available.rbegin(), available.rend());

        priority_queue<int> pq;
        int poured = 0;
        for (int i = 0; i < n; ++i) {
            pq.push(a[i]);
            poured += a[i];
            if (pq.size() > k) {
                int top = pq.top();
                pq.pop();
                poured -= top;
            }
            if (poured > t) return false;
        }

        int used_bottles = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > 0) {
                used_bottles++;
                int needed = a[i];
                for (int j = 0; j < available.size() && needed > 0; ++j) {
                    int fill = min(needed, available[j].first);
                    available[j].first -= fill;
                    needed -= fill;
                }
            }
        }

        return used_bottles <= k;
    };

    int min_k = 1, max_k = n;
    while (min_k < max_k) {
        int mid_k = (min_k + max_k) / 2;
        bool possible = false;
        for (int t = 0; t <=10000; ++t) {
            if (can_fit(mid_k, t)) {
                possible = true;
                break;
            }
        }
        if (possible) {
            max_k = mid_k;
        } else {
            min_k = mid_k + 1;
        }
    }

    int min_t = 0;
    for (int t = 0; t <=10000; ++t) {
        if (can_fit(min_k, t)) {
            min_t = t;
            break;
        }
    }

    cout << min_k <<   << min_t << "\n";
    return 0;
}