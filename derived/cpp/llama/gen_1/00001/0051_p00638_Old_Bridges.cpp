#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<pair<int, int>> islands(n);
        for (int i = 0; i < n; i++) {
            cin >> islands[i].first >> islands[i].second;
        }
        sort(islands.begin(), islands.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += islands[i].first;
        }
        bool possible = false;
        for (int i = 0; i < n; i++) {
            if (islands[i].second >= sum) {
                possible = true;
                break;
            }
        }
        if (possible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}