#include <bits/stdc++.h>
using namespace std;

int crossProduct(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
    return (B.first - A.first) * (C.second - B.second) - (B.second - A.second) * (C.first - B.first);
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (auto &p : points) {
        cin >> p.first >> p.second;
    }
    int sign = 0;
    for (int i = 0; i < n; ++i) {
        int cp = crossProduct(points[i], points[(i + 1) % n], points[(i + 2) % n]);
        if (cp != 0) {
            if (sign == 0) sign = cp > 0 ? 1 : -1;
            else if ((cp > 0 && sign == -1) || (cp < 0 && sign == 1)) {
                cout << "0";
                return 0;
            }
        }
    }
    cout << "1";
}