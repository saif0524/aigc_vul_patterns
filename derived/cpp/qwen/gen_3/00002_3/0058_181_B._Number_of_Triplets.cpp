#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (auto &p : points) {
        cin >> p.first >> p.second;
    }

    unordered_map<int, unordered_map<int, int>> count;

    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int dx = points[i].first - points[j].first;
            int dy = points[i].second - points[j].second;
            int midX = points[i].first - dx / 2;
            int midY = points[i].second - dy / 2;
            if (dx % 2 == 0 && dy % 2 == 0) {
                result += count[midX][midY];
            }
            count[points[j].first + dx / 2][points[j].second + dy / 2]++;
        }
    }

    cout << result << endl;
    return 0;
}