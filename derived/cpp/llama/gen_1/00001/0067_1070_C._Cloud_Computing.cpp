#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long solve(int n, int k, vector<vector<int>>& plans) {
    vector<vector<pair<int, int>>> days(n);
    for (auto& p : plans) {
        for (int i = p[0] - 1; i < p[1]; i++) {
            days[i].emplace_back(p[2], p[3]);
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        sort(days[i].begin(), days[i].end(), [](auto& a, auto& b) { return a.second < b.second; });
        int cores = 0;
        int cost = 0;
        for (auto& p : days[i]) {
            int c = min(p.first, k - cores);
            cores += c;
            cost += (long long)c * p.second;
            if (cores >= k) break;
        }
        ans += cost;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, m;
    cin >> n >> k >> m;
    vector<vector<int>> plans(m, vector<int>(4));
    for (int i = 0; i < m; i++) {
        cin >> plans[i][0] >> plans[i][1] >> plans[i][2] >> plans[i][3];
    }
    long long ans = solve(n, k, plans);
    cout << ans << '\n';
    return 0;
}