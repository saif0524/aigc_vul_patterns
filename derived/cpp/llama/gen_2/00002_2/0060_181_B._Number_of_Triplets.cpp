#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.insert({x, y});
    }

    int count = 0;
    for (auto& p1 : points) {
        for (auto& p2 : points) {
            if (p1 == p2) continue;
            int midX = (p1.first + p2.first) / 2;
            int midY = (p1.second + p2.second) / 2;
            if (points.find({midX, midY})!= points.end()) {
                count++;
            }
        }
    }

    cout << count / 2 << endl;

    return 0;
}