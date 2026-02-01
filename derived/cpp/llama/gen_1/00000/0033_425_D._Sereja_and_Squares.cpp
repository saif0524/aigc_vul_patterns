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
        points.insert(make_pair(x, y));
    }

    int count = 0;
    for (auto it = points.begin(); it != points.end(); it++) {
        int x1 = it->first;
        int y1 = it->second;

        for (auto jt = next(it); jt != points.end(); jt++) {
            int x2 = jt->first;
            int y2 = jt->second;

            if (x1 != x2 && y1 != y2) {
                if (points.count(make_pair(x1, y2)) && points.count(make_pair(x2, y1))) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}