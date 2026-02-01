#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = acos(-1.0);

int main() {
    int n, px, py;
    cin >> n >> px >> py;

    vector<int> vx(n), vy(n);
    for (int i = 0; i < n; i++) {
        cin >> vx[i] >> vy[i];
    }

    double area = 0.0;
    double r = 0.0;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        double cross = (vx[i] - px) * (vy[j] - py) - (vy[i] - py) * (vx[j] - px);
        area += cross;
        double dist = sqrt(pow(vx[i] - px, 2) + pow(vy[i] - py, 2));
        r = max(r, dist);
    }

    area = abs(area) / 2.0;
    double res = PI * pow(r, 2);

    cout << fixed << setprecision(17) << res << endl;

    return 0;
}