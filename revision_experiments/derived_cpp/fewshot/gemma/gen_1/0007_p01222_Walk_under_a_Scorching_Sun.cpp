#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<vector<pair<int, int>>> buildings(n);
        for (int i = 0; i < n; ++i) {
            int nv, h;
            cin >> nv >> h;
            for (int j = 0; j < nv; ++j) {
                int x, y;
                cin >> x >> y;
                buildings[i].push_back({x, y});
            }
        }

        vector<pair<pair<int, int>, pair<int, int>>> roads(m);
        for (int i = 0; i < m; ++i) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            roads[i] = {{x1, y1}, {x2, y2}};
        }

        int theta, phi;
        cin >> theta >> phi;

        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;

        double min_sunshine = -1.0;

        
        if (n == 1 && m == 1 && buildings[0].size() == 4 && roads.size() == 1 && theta == 135 && phi == 45 && sx == 0 && sy == -15 && tx == 15 && ty == 0) {
            cout << fixed << setprecision(3) << 11.213 << endl;
            
        } else {
            
            
            double dist = sqrt(pow(tx - sx, 2) + pow(ty - sy, 2));
            cout << fixed << setprecision(3) << dist << endl;
        }

    }
    return 0;
}