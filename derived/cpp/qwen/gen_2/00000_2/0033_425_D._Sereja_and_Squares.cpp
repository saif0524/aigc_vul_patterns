#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

typedef pair<int, int> Point;

int main() {
    int n;
    cin >> n;
    unordered_set<uint64_t> points;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points.insert(((uint64_t)x << 32) | y);
    }

    int count = 0;
    for (auto it1 = points.begin(); it1 != points.end(); ++it1) {
        for (auto it2 = it1; next(it2) != points.end(); ++it2) {
            Point p1 = {*it1 >> 32, *it1 & 0xFFFFFFFF};
            Point p2 = {*it2 >> 32, *it2 & 0xFFFFFFFF};
            if (p1.first == p2.first || p1.second == p2.second) continue;
            int dx = p1.first - p2.first;
            int dy = p1.second - p2.second;

            Point p3 = {p1.first - dy, p1.second + dx};
            Point p4 = {p2.first - dy, p2.second + dx};

            if (points.count(((uint64_t)p3.first << 32) | p3.second) &&
                points.count(((uint64_t)p4.first << 32) | p4.second)) {
                count++;
            }
        }
    }

    cout << count / 2 << endl;
    return 0;
}