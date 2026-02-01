#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int m = max(abs((x1 + y1) / (2 * a)), abs((x1 - y1) / (2 * b)));
    int n = max(abs((x2 + y2) / (2 * a)), abs((x2 - y2) / (2 * b)));

    cout << max(abs((x1 + y1) / (2 * a) - (x2 + y2) / (2 * a)), abs((x1 - y1) / (2 * b) - (x2 - y2) / (2 * b))) << endl;

    return 0;
}