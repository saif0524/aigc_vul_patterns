#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t1, t2, x1, x2, t0;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;

    int y1 = x1, y2 = 0;
    double temperature = (t1 * y1) / (y1 + y2);
    if (temperature >= t0) {
        cout << y1 << " " << y2 << endl;
    } else {
        for (int i = 0; i <= x2; i++) {
            double temp = (t1 * y1 + t2 * i) / (y1 + i);
            if (temp >= t0 && temp <= temperature) {
                temperature = temp;
                y2 = i;
            }
        }
        for (int i = x1; i >= 0; i--) {
            double temp = (t1 * i + t2 * y2) / (i + y2);
            if (abs(temp - t0) < abs(temperature - t0)) {
                temperature = temp;
                y1 = i;
            }
        }
        cout << y1 << " " << y2 << endl;
    }

    return 0;
}