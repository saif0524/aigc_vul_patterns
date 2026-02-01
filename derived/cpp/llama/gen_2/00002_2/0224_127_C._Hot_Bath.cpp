#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t1, t2, x1, x2, t0;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;

    double y1 = 0, y2 = 0;
    double minDiff = 1e9;

    for (int i = 0; i <= x1; i++) {
        for (int j = 0; j <= x2; j++) {
            if (i + j == 0) continue;
            double temp = (i * t1 + j * t2) / (i + j);
            double diff = abs(temp - t0);
            if (diff < minDiff) {
                minDiff = diff;
                y1 = i;
                y2 = j;
            } else if (diff == minDiff) {
                if (i + j > y1 + y2) {
                    y1 = i;
                    y2 = j;
                }
            }
        }
    }

    cout << y1 << " " << y2 << endl;

    return 0;
}