#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }

    unordered_map<int, unordered_map<int, bool>> uf;
    for (const auto& point : p) {
        uf[point.first][point.second] = true;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int midX = p[i].first + p[j].first;
            int midY = p[i].second + p[j].second;
            if ((midX % 2 == 0) && (midY % 2 == 0)) {
                int mx = midX / 2;
                int my = midY / 2;
                if (uf.count(mx) && uf[mx].count(my)) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}