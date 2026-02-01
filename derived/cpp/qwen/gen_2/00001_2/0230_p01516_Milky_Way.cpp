#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <tuple>
#include <iomanip>

using namespace std;

struct Star {
    double x, y, a, r;
};

double dist(const Star &s1, const Star &s2) {
    double dx = s1.x - s2.x;
    double dy = s1.y - s2.y;
    return sqrt(dx * dx + dy * dy);
}

bool intersects(const Star &s1, const Star &s2) {
    double d = dist(s1, s2);
    return d <= s1.r + s2.r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, L;
    while (cin >> N >> M >> L, N || M || L) {
        vector<Star> stars(N);
        for (int i = 0; i < N; ++i) {
            cin >> stars[i].x >> stars[i].y >> stars[i].a >> stars[i].r;
        }

        vector<vector<int>> graph(N);
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (intersects(stars[i], stars[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        vector<double> dists(N, INFINITY);
        dists[M-1] = 0;
        pq.emplace(0, M-1);

        while (!pq.empty()) {
            double d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dists[u]) continue;

            for (int v : graph[u]) {
                double new_d = dist(stars[u], stars[v]);
                if (d + new_d < dists[v]) {
                    dists[v] = d + new_d;
                    pq.emplace(d + new_d, v);
                }
            }
        }

        cout << fixed << setprecision(20) << dists[L-1] << "\n";
    }
}