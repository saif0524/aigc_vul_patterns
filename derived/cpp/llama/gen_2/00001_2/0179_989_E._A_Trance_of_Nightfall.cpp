#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

const int N = 210;

struct point {
    int x, y, id;
    bool operator<(const point& other) const {
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
};

int n;
point p[N];
int deg[N];
std::map<int, int> mp;

double dp[N][N];
std::vector<int> G[N];

bool check(point a, point b, point c) {
    return 1LL * (b.x - a.x) * (c.y - a.y) == 1LL * (b.y - a.y) * (c.x - a.x);
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int k = (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
            mp[k] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        deg[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int k = (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
            deg[p[i].id]++;
            deg[p[j].id]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        deg[i] /= 2;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                dp[i][j] = 1.0 / deg[j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        G[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                G[i].push_back(j);
            }
        }
    }
    int q;
    std::cin >> q;
    for (int i = 1; i <= q; i++) {
        int t, m;
        std::cin >> t >> m;
        double ans = 0;
        for (int j = 1; j <= n; j++) {
            if (deg[j] != 0) {
                double cur = 1.0;
                for (int k = 1; k <= m; k++) {
                    double tmp = 0;
                    for (int x : G[j]) {
                        tmp += dp[j][x];
                    }
                    cur *= tmp;
                    j = x;
                    for (int x : G[j]) {
                        dp[j][x] = 1.0 / deg[x];
                    }
                }
                if (j == t) {
                    ans = std::max(ans, cur);
                }
            }
        }
        std::cout << std::fixed << std::setprecision(20) << ans << std::endl;
    }
    return 0;
}