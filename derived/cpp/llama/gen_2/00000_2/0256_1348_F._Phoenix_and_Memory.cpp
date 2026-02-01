#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        order[i] = i;
    }

    sort(order.begin(), order.end(), [&](int i, int j) {
        return intervals[i].first < intervals[j].first;
    });

    vector<int> first_order(n);
    for (int i = 0; i < n; ++i) {
        first_order[i] = order[i] + 1;
    }

    bool is_unique = true;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (intervals[i].first <= first_order[j] && first_order[j] <= intervals[i].second &&
                intervals[j].first <= first_order[i] && first_order[i] <= intervals[j].second) {
                is_unique = false;

                vector<int> second_order = first_order;
                swap(second_order[i], second_order[j]);

                cout << "NO\n";
                for (int num : first_order) {
                    cout << num << ' ';
                }
                cout << '\n';
                for (int num : second_order) {
                    cout << num << ' ';
                }
                cout << '\n';

                return 0;
            }
        }
    }

    cout << "YES\n";
    for (int num : first_order) {
        cout << num << ' ';
    }
    cout << '\n';

    return 0;
}