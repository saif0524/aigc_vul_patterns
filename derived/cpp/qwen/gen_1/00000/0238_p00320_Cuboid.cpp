#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, int>> rectangles(6);
    for (auto &rect : rectangles) {
        cin >> rect.first >> rect.second;
        if (rect.first > rect.second) {
            swap(rect.first, rect.second);
        }
    }
    sort(rectangles.begin(), rectangles.end());
    if ((rectangles[0] == rectangles[1] && rectangles[1] == rectangles[2] &&
         rectangles[3] == rectangles[4] && rectangles[4] == rectangles[5] &&
         rectangles[0].first == rectangles[3].first) ||
        (rectangles[0] == rectangles[1] && rectangles[1] == rectangles[3] &&
         rectangles[2] == rectangles[4] && rectangles[4] == rectangles[5] &&
         rectangles[0].second == rectangles[2].first) ||
        (rectangles[0] == rectangles[2] && rectangles[2] == rectangles[3] &&
         rectangles[1] == rectangles[4] && rectangles[4] == rectangles[5] &&
         rectangles[0].second == rectangles[1].first)) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}