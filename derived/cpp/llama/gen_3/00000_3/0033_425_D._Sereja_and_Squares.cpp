#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<pair<int, int>, int> points;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[{x, y}] = 1;
        arr.push_back({x, y});
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = arr[i].first;
            int y1 = arr[i].second;
            int x2 = arr[j].first;
            int y2 = arr[j].second;
            if (x1 == x2 || y1 == y2) continue;
            if (points.find({x1, y2}) != points.end() && points.find({x2, y1}) != points.end()) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}