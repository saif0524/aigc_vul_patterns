#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, int>> rectangles(6);
    for (auto &r : rectangles) {
        cin >> r.first >> r.second;
        if (r.first > r.second) swap(r.first, r.second);
    }
    sort(rectangles.begin(), rectangles.end());

    if (rectangles[0] == rectangles[1] && rectangles[1] == rectangles[2] &&
        rectangles[3] == rectangles[4] && rectangles[4] == rectangles[5] &&
        rectangles[0].first == rectangles[3].first) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}