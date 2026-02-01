#include <iostream>
#include <vector>

using namespace std;

double crossProduct(const pair<int, int>& a, const pair<int, int>& b, const pair<int, int>& c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    bool isConvex = true;
    int sign = 0;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int k = (j + 1) % n;

        double cp = crossProduct(points[i], points[j], points[k]);

        if (sign == 0) {
            sign = (cp > 0) ? 1 : -1;
        } else if ((cp > 0 && sign < 0) || (cp < 0 && sign > 0)) {
            isConvex = false;
            break;
        }
    }

    cout << (isConvex ? "1" : "0") << endl;

    return 0;
}