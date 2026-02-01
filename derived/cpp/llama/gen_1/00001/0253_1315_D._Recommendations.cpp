#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[i].second;
    }

    sort(a.begin(), a.end());

    long long result = 0;
    int last = a[0].first;

    vector<pair<int, int>> queue;

    for (int i = 0; i < n; ++i) {
        if (a[i].first > last) {
            sort(queue.begin(), queue.end(), [](const auto& x, const auto& y) {
                return x.second > y.second;
            });

            for (const auto& p : queue) {
                result += static_cast<long long>(p.second) * (last - p.first);
                last++;
            }

            queue.clear();
            last = a[i].first;
        }

        if (last == a[i].first) {
            queue.emplace_back(a[i].first, a[i].second);
        } else {
            result += static_cast<long long>(a[i].second) * (last - a[i].first);
            last++;
        }
    }

    sort(queue.begin(), queue.end(), [](const auto& x, const auto& y) {
        return x.second > y.second;
    });

    for (const auto& p : queue) {
        result += static_cast<long long>(p.second) * (last - p.first);
        last++;
    }

    cout << result << endl;

    return 0;
}