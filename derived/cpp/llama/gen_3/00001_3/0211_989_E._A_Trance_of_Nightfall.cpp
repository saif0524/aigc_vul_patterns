#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

const int MAXN = 200 + 5;
const long double EPS = 1e-12;

struct Point {
    int x, y;
};

inline long double getProb(int from, int to, const vector<vector<long double>>& prob) {
    if (prob[from][to] > 0.5 - EPS) {
        return from == to ? 1.0 : 0.5;
    }
    return (long double)prob[from][to] / prob[from][from];
}

inline bool onLine(const Point& p1, const Point& p2, const Point& p3) {
    long double s1 = (long double)(p2.x - p1.x) * (p3.y - p1.y);
    long double s2 = (long double)(p3.x - p1.x) * (p2.y - p1.y);
    return fabs(s1 - s2) < EPS;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<set<int>> lines(n);
    map<pair<int, int>, int> lineId;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int id = lineId.size();
            lineId[make_pair(i, j)] = id;
            lineId[make_pair(j, i)] = id;

            for (int k = 0; k < n; k++) {
                if (onLine(points[i], points[j], points[k])) {
                    lines[k].insert(id);
                }
            }
        }
    }

    vector<vector<int>> numLines(n, vector<int>(n));
    vector<vector<long double>> prob(n, vector<long double>(n, 0.0));

    for (int i = 0; i < n; i++) {
        for (int j : lines[i]) {
            for (int k = 0; k < n; k++) {
                if (lines[k].count(j)) {
                    numLines[i][k]++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (numLines[i][k] > 0) {
                prob[i][k] = 1.0 / numLines[i][k];
            }
        }
    }

    int q;
    cin >> q;

    for (int it = 0; it < q; it++) {
        int t, m;
        cin >> t >> m;

        t--;

        long double ans = 0.0;

        for (int i = 0; i < n; i++) {
            if (!lines[i].empty()) {
                vector<long double> curProb(n, 0.0);

                curProb[i] = 1.0;

                for (int step = 0; step < m; step++) {
                    vector<long double> nextProb(n, 0.0);

                    for (int j = 0; j < n; j++) {
                        for (int k = 0; k < n; k++) {
                            nextProb[k] += curProb[j] * prob[j][k];
                        }
                    }

                    curProb = nextProb;
                }

                ans = max(ans, getProb(i, t, prob) * curProb[t]);
            }
        }

        cout << fixed << setprecision(18) << ans << '\n';
    }

    return 0;
}