#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, map<int, bool>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[x][y] = true;
    }
    int count = 0;
    for (auto& px : points) {
        for (auto& py : px.second) {
            int x = px.first;
            int y = py.first;
            for (int w = 1; w <= 100; w++) {
                if (points.find(x) != points.end() && points[x].find(y) != points[x].end() &&
                    points.find(x + w) != points.end() && points[x + w].find(y) != points[x + w].end() &&
                    points.find(x) != points.end() && points[x].find(y + w) != points[x].end() &&
                    points.find(x + w) != points.end() && points[x + w].find(y + w) != points[x + w].end()) {
                    count++;
                }
                if (points.find(x) != points.end() && points[x].find(y) != points[x].end() &&
                    points.find(x - w) != points.end() && points[x - w].find(y) != points[x - w].end() &&
                    points.find(x) != points.end() && points[x].find(y + w) != points[x].end() &&
                    points.find(x - w) != points.end() && points[x - w].find(y + w) != points[x - w].end()) {
                    count++;
                }
                if (points.find(x) != points.end() && points[x].find(y) != points[x].end() &&
                    points.find(x - w) != points.end() && points[x - w].find(y) != points[x - w].end() &&
                    points.find(x) != points.end() && points[x].find(y - w) != points[x].end() &&
                    points.find(x - w) != points.end() && points[x - w].find(y - w) != points[x - w].end()) {
                    count++;
                }
                if (points.find(x) != points.end() && points[x].find(y) != points[x].end() &&
                    points.find(x + w) != points.end() && points[x + w].find(y) != points[x + w].end() &&
                    points.find(x) != points.end() && points[x].find(y - w) != points[x].end() &&
                    points.find(x + w) != points.end() && points[x + w].find(y - w) != points[x + w].end()) {
                    count++;
                }
            }
        }
    }
    cout << count / 4 << endl;
    return 0;
}