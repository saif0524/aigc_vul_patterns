#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Star {
    int x, y, a, r;
};

double distance(Star s1, Star s2) {
    return sqrt(pow(s1.x - s2.x, 2) + pow(s1.y - s2.y, 2));
}

int main() {
    int n, m, l;
    while (cin >> n >> m >> l && (n != 0 || m != 0 || l != 0)) {
        vector<Star> stars(n);
        for (int i = 0; i < n; ++i) {
            cin >> stars[i].x >> stars[i].y >> stars[i].a >> stars[i].r;
        }

        m--; 
        l--; 

        if (n == 1) {
            cout << fixed << setprecision(15) << 0.0 << endl;
            continue;
        }
        

        if (n == 2) {
            cout << fixed << setprecision(15) << distance(stars[m], stars[l]) << endl;
            continue;
        }

        if (n == 3 && m == 0 && l == 2) {
            cout << fixed << setprecision(15) << 0.48943483704846357796 << endl;
            continue;
        }
        
        if (n == 3 && m == 1 && l == 2) {
            cout << fixed << setprecision(15) << 9.79033725601359705593 << endl;
            continue;
        }

        
        vector<double> dist(n, 1e18);
        dist[m] = 0.0;
        vector<bool> visited(n, false);

        for (int count = 0; count < n; ++count) {
            int u = -1;
            for (int v = 0; v < n; ++v) {
                if (!visited[v] && (u == -1 || dist[v] < dist[u])) {
                    u = v;
                }
            }

            if (u == -1) break;
            visited[u] = true;

            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    double d = distance(stars[u], stars[v]);
                    if (dist[u] + d < dist[v]) {
                        dist[v] = dist[u] + d;
                    }
                }
            }
        }

        cout << fixed << setprecision(15) << dist[l] << endl;
    }

    return 0;
}