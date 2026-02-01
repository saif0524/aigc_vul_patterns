#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const long double EPS = 1e-12;
const long double PI = acos(-1.0L);

pair<int, int> operator-(const pair<int, int>& a, const pair<int, int>& b) {
    return {a.first - b.first, a.second - b.second};
}

long double scal(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first * 1.0L * b.first + a.second * 1.0L * b.second;
}

long double abs(const pair<int, int>& a) {
    return sqrt(a.first * 1.0L * a.first + a.second * 1.0L * a.second);
}

long double rad(const pair<int, int>& a) {
    return atan2(a.second, a.first);
}

int main() {
    int n;
    pair<int, int> p;
    cin >> n >> p.first >> p.second;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    long double ans = 0;
    for (int i = 0; i < n; i++) {
        pair<int, int> a = v[i] - p, b = v[(i + 1) % n] - p;
        long double alfa = rad(a), beta = rad(b);
        if (beta < alfa) beta += 2 * PI;

        ans += (beta - alfa) * (abs(a) * abs(a)) / 2.0L;
    }

    cout.precision(16);
    cout << fixed << ans << endl;

    return 0;
}