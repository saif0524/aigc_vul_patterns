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
    
    int maxReach = 0;
    for (const auto &t : teleports) {
        if (t.first <= maxReach) {
            maxReach = max(maxReach, t.second);
        }
    }
    
    if (maxReach >= m) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}