#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<int, int>> rectangles(6);
    for (int i = 0; i < 6; ++i) {
        cin >> rectangles[i].first >> rectangles[i].second;
        if (rectangles[i].first > rectangles[i].second) {
            swap(rectangles[i].first, rectangles[i].second);
        }
    }
    sort(rectangles.begin(), rectangles.end());

    bool valid = true;
    for (int i = 0; i < 6; i += 2) {
        if (rectangles[i] != rectangles[i + 1]) {
            valid = false;
            break;
        }
    }

    if (valid) {
        if (rectangles[0] == rectangles[2] && rectangles[2] == rectangles[4]) {
            valid = false;
        }
    }

    cout << (valid ? "yes" : "no") << endl;
    return 0;
}