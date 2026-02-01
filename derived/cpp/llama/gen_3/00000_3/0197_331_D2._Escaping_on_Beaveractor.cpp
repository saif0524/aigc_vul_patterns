#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;

    vector<vector<int>> rules(n, vector<int>(4));
    for (int i = 0; i < n; i++) {
        cin >> rules[i][0] >> rules[i][1] >> rules[i][2] >> rules[i][3];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        char dir;
        cin >> dir;
        long long t;
        cin >> t;

        int dx = 0, dy = 0;
        if (dir == 'U') dy = 1;
        if (dir == 'D') dy = -1;
        if (dir == 'R') dx = 1;
        if (dir == 'L') dx = -1;

        for (long long j = 0; j < t; j++) {
            x += dx;
            y += dy;

            if (x < 0 || x > b || y < 0 || y > b) {
                x -= dx;
                y -= dy;
                break;
            }

            for (int k = 0; k < n; k++) {
                if (x == rules[k][0] && y == rules[k][1]) {
                    if (rules[k][0] == rules[k][2]) {
                        dy = (rules[k][3] > rules[k][1]) - (rules[k][3] < rules[k][1]);
                        dx = 0;
                    } else {
                        dx = (rules[k][2] > rules[k][0]) - (rules[k][2] < rules[k][0]);
                        dy = 0;
                    }
                }
            }
        }

        cout << x << " " << y << endl;
    }

    return 0;
}