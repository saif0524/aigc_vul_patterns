#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> teleports(n);
    for (auto &t : teleports) {
        cin >> t.first >> t.second;
    }
    int max_reach = 0;
    for (const auto &t : teleports) {
        if (t.first <= max_reach) {
            max_reach = max(max_reach, t.second);
        }
        if (max_reach >= m) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}