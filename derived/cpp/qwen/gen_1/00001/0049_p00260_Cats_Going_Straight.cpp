#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n;
vector<pii> points;

bool is_visible(int p1, int p2, vector<bool> &visible) {
    double x1 = points[p1].first, y1 = points[p1].second;
    double x2 = points[p2].first, y2 = points[p2].second;
    for (int i = 0; i < n; ++i) {
        if (i != p1 && i != p2) {
            double x3 = points[i].first, y3 = points[i].second;
            double cross = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
            if (cross != 0) {
                double dx = x2 - x1, dy = y2 - y1;
                double t = (x3 - x1) * dx + (y3 - y1) * dy;
                t /= dx * dx + dy * dy;
                double xp = x1 + dx * t, yp = y1 + dy * t;
                if (t >= 0 && t <= 1) {
                    double dist_sq = (xp - x3) * (xp - x3) + (yp - y3) * (yp - y3);
                    double r_sq = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                    if (dist_sq < r_sq) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int dp[17];

int solve(int mask) {
    if (dp[mask] != -1) return dp[mask];
    int res = n;
    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
            bool good = true;
            for (int j = 0; j < n; ++j) {
                if (!(mask & (1 << j)) && !is_visible(i, j, vector<bool>(n))) {
                    good = false;
                    break;
                }
            }
            if (good) {
                res = 1;
                break;
            }
            for (int sub = (mask - 1) & mask; sub; sub = (sub - 1) & mask) {
                if (sub & (1 << i)) {
                    int curr = solve(sub) + solve(mask ^ sub);
                    res = min(res, curr);
                }
            }
        }
    }
    return dp[mask] = res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n && n) {
        points.resize(n);
        for(int i=0;i<n;i++){
            cin >> points[i].first >> points[i].second;
        }
        memset(dp, -1, sizeof(dp));
        cout << solve((1<<n)-1) << "\n";
    }
}