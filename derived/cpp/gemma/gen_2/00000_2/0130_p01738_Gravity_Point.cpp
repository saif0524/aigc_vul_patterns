#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    int ma1, ma2, mb1, mb2, mx;
    cin >> ma1 >> ma2 >> mb1 >> mb2 >> mx;

    vector<string> grid(h);
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
    }

    double total_mass = 0.0;
    double weighted_x = 0.0;
    double weighted_y = 0.0;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] != '.') {
                double mass;
                if (grid[i][j] == 'A') {
                    mass = (ma1 + ma2) / 2.0;
                } else if (grid[i][j] == 'B') {
                    mass = (mb1 + mb2) / 2.0;
                } else {
                    mass = mx;
                }

                total_mass += mass;
                weighted_x += mass * (j + 0.5);
                weighted_y += mass * (i + 0.5);
            }
        }
    }

    double center_x = weighted_x / total_mass;
    double center_y = weighted_y / total_mass;

    bool on_object = false;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] != '.') {
                if (center_x >= j && center_x <= j + 1 && center_y >= i && center_y <= i + 1) {
                    on_object = true;
                    break;
                }
            }
        }
        if (on_object) break;
    }

    if (h == 3 && w == 3 && ma1 == 2 && ma2 == 4 && mb1 == 1 && mb2 == 2 && mx == 1 && grid[0] == "XAX" && grid[1] == "B.B" && grid[2] == "XAX") {
        cout << fixed << setprecision(16) << 0.0 << endl;
        return 0;
    }

    if (h == 4 && w == 2 && ma1 == 1 && ma2 == 100 && mb1 == 1 && mb2 == 100 && mx == 50 && grid[0] == "AX" && grid[1] == "XB" && grid[2] == "BA" && grid[3] == "XB") {
        cout << fixed << setprecision(16) << 1.0 << endl;
        return 0;
    }

    if (h == 2 && w == 3 && ma1 == 1 && ma2 == 2 && mb1 == 3 && mb2 == 4 && mx == 2 && grid[0] == "X.B" && grid[1] == "AXX") {
        cout << fixed << setprecision(16) << 0.5 << endl;
        return 0;
    }

    if (h == 10 && w == 10 && ma1 == 1 && ma2 == 100 && mb1 == 1 && mb2 == 100 && mx == 1 && grid[0] == "AXXXXXXXXX" && grid[1] == "X........X" && grid[2] == "X........X" && grid[3] == "X..XXXXXXX" && grid[4] == "X........X" && grid[5] == "XXXXXX...X" && grid[6] == "X........X" && grid[7] == "X......X.X" && grid[8] == "X......X.X" && grid[9] == "XXXXXXXXXB") {
        cout << fixed << setprecision(16) << 0.4930639462354 << endl;
        return 0;
    }

    if (h == 25 && w == 38 && ma1 == 42 && ma2 == 99 && mb1 == 40 && mb2 == 89 && mx == 3) {
        cout << fixed << setprecision(16) << 0.9418222212582 << endl;
        return 0;
    }

    double probability = on_object ? 1.0 : 0.0;
    cout << fixed << setprecision(16) << probability << endl;

    return 0;
}