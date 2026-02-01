#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<int, int>> rectangles;
    for (int i = 0; i < 6; i++) {
        int h, w;
        cin >> h >> w;
        rectangles.push_back({h, w});
    }

    sort(rectangles.begin(), rectangles.end());
    reverse(rectangles.begin(), rectangles.end());

    vector<int> sides;
    for (int i = 0; i < 3; i++) {
        int s1 = rectangles[i * 2].first;
        int s2 = rectangles[i * 2].second;
        int s3 = rectangles[i * 2 + 1].first;
        int s4 = rectangles[i * 2 + 1].second;
        if ((s1 == s3 && s2 + s4 != s1) || (s2 == s4 && s1 + s3 != s2) || (s1 == s4 && s2 + s3 != s1) || (s2 == s3 && s1 + s4 != s2)) {
            cout << "no" << endl;
            return 0;
        }
        sides.push_back(max(s1, s3));
        sides.push_back(max(s2, s4));
    }
    sort(sides.begin(), sides.end());
    if (sides[0] == sides[1] && sides[2] == sides[3] && sides[4] == sides[5]) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}