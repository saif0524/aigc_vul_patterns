#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, int>> rectangles(6);
    for (auto& rect : rectangles) {
        cin >> rect.first >> rect.second;
    }

    sort(begin(rectangles), end(rectangles));

    int h1 = rectangles[0].first;
    int w1 = rectangles[0].second;
    int h2 = rectangles[1].first;
    int w2 = rectangles[1].second;
    int h3 = rectangles[2].first;
    int w3 = rectangles[2].second;
    int h4 = rectangles[3].first;
    int w4 = rectangles[3].second;
    int h5 = rectangles[4].first;
    int w5 = rectangles[4].second;
    int h6 = rectangles[5].first;
    int w6 = rectangles[5].second;

    if ((h1 == h2 && w1 == w2 && h3 == h4 && w3 == w4 && h5 == h6 && w5 == w6) &&
        (h1 == w3 && w1 == h3 && h5 == w3 && w5 == h3)) {
        cout << "yes" << endl;
    } else if ((h1 == h2 && w1 == w2 && h3 == h4 && w3 == w4 && h5 == h6 && w5 == w6) &&
               (h1 == w5 && w1 == h5 && h3 == w5 && w3 == h5)) {
        cout << "yes" << endl;
    } else if ((h1 == h2 && w1 == w2 && h3 == h4 && w3 == w4 && h5 == h6 && w5 == w6) &&
               (h1 == h5 && w1 == w5 && h3 == w5 && w3 == h5)) {
        cout << "yes" << endl;
    } else if ((h1 == h4 && w1 == w4 && h2 == h3 && w2 == w3 && h5 == h6 && w5 == w6) &&
               (h1 == w5 && w1 == h5 && h2 == w5 && w2 == h5)) {
        cout << "yes" << endl;
    } else if ((h1 == h4 && w1 == w4 && h2 == h3 && w2 == w3 && h5 == h6 && w5 == w6) &&
               (h1 == h5 && w1 == w5 && h2 == w5 && w2 == h5)) {
        cout << "yes" << endl;
    } else if ((h1 == h4 && w1 == w4 && h2 == h3 && w2 == w3 && h5 == h6 && w5 == w6) &&
               (h2 == w5 && w2 == h5 && h1 == w5 && w1 == h5)) {
        cout << "yes" << endl;
    } else if ((h1 == h6 && w1 == w6 && h2 == h3 && w2 == w3 && h4 == h5 && w4 == w5) &&
               (h1 == w2 && w1 == h2 && h4 == w2 && w4 == h2)) {
        cout << "yes" << endl;
    } else if ((h1 == h6 && w1 == w6 && h2 == h3 && w2 == w3 && h4 == h5 && w4 == w5) &&
               (h1 == h2 && w1 == w2 && h4 == w2 && w4 == h2)) {
        cout << "yes" << endl;
    } else if ((h1 == h6 && w1 == w6 && h2 == h3 && w2 == w3 && h4 == h5 && w4 == w5) &&
               (h4 == w2 && w4 == h2 && h1 == w2 && w1 == h2)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}