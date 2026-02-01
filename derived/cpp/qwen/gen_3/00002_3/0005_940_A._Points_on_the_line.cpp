#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> points(n);
    for (int &x : points) cin >> x;
    sort(points.begin(), points.end());
    
    int min_removals = n;
    for (int i = 0; i < n; ++i) {
        int j = lower_bound(points.begin() + i, points.end(), points[i] + d + 1) - points.begin() - 1;
        min_removals = min(min_removals, n - (j - i + 1));
    }
    
    cout << min_removals;
}