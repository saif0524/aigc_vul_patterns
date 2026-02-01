#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x : a) cin >> x;
    int m;
    cin >> m;
    vector<pair<int, int>> queries(m);
    for(auto &q : queries) cin >> q.first >> q.second;

    for(const auto &[k, pos] : queries) {
        vector<pair<long long, int>> values;
        for(int i = 0; i < n; ++i) {
            values.emplace_back(a[i], i);
        }
        sort(values.begin(), values.end(), [&](const pair<long long, int> &p1, const pair<long long, int> &p2) {
            if(p1.first != p2.first) return p1.first > p2.first;
            return p1.second < p2.second;
        });

        vector<long long> selected_values;
        int used = 0;
        for(int i = 0; i < n && used < k; ++i) {
            bool can_select = true;
            for(int j = i + 1; j < n && can_select; ++j) {
                if(values[j].first > values[i].first && n - j < k - used) {
                    can_select = false;
                }
            }
            if(can_select) {
                selected_values.push_back(values[i].first);
                used++;
            }
        }
        cout << selected_values[pos - 1] << "\n";
    }
    return 0;
}