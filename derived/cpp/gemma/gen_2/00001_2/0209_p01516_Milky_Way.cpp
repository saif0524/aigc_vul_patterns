#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Star {
    int x, y, a, r;
};

double dist(Star s1, Star s2) {
    return sqrt(pow(s1.x - s2.x, 2) + pow(s1.y - s2.y, 2));
}

int main() {
    int n, m, l;
    while (cin >> n >> m >> l && (n != 0 || m != 0 || l != 0)) {
        vector<Star> stars(n);
        for (int i = 0; i < n; ++i) {
            cin >> stars[i].x >> stars[i].y >> stars[i].a >> stars[i].r;
        }

        --m; --l;

        vector<double> d(n, 1e18);
        d[m] = 0.0;
        vector<bool> visited(n, false);

        for (int count = 0; count < n; ++count) {
            int u = -1;
            for (int v = 0; v < n; ++v) {
                if (!visited[v] && (u == -1 || d[v] < d[u])) {
                    u = v;
                }
            }

            if (u == -1) break;

            visited[u] = true;

            for (int v = 0; v < n; ++v) {
                double distance = dist(stars[u], stars[v]);
                if (distance < stars[u].r && distance < stars[v].r) {
                   
                } else {
                    d[v] = min(d[v], d[u] + distance);
                }
            }
        }

        cout << fixed << setprecision(16) << d[l] << endl;
    }

    return 0;
}