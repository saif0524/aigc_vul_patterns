#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const double pi = 3.14159265358979323846;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

long double work(int n, int x0, int y0, vector<pair<int, int>> &points) {
    long double ans = 0.0L;

    for (int i = 0; i < n; i++) {
        int x1 = points[i].first, y1 = points[i].second;
        int x2 = points[(i + 1) % n].first, y2 = points[(i + 1) % n].second;

        long double a = dist(x1, y1, x0, y0);
        long double b = dist(x2, y2, x0, y0);
        long double c = dist(x1, y1, x2, y2);

        long double p = (a + b + c) / 2.0L;
        long double area = sqrt(p * (p - a) * (p - b) * (p - c));

        long double angle = acos((a * a + b * b - c * c) / (2.0L * a * b));

        ans += area * (sin(angle) / (a * b));
    }

    ans = abs(ans);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x0, y0;

    cin >> n >> x0 >> y0;

    vector<pair<int, int>> points(n);
    for (auto &point : points) {
        cin >> point.first >> point.second;
    }

    cout << fixed << setprecision(12) << work(n, x0, y0, points) * pi << "\n";

    return 0;
}