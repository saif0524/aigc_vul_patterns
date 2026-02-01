#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> teleports(n);
    for (int i = 0; i < n; i++) {
        cin >> teleports[i].first >> teleports[i].second;
    }

    int current = 0;
    for (int i = 0; i < n; i++) {
        if (teleports[i].first > current) {
            break;
        }
        current = max(current, teleports[i].second);
    }

    if (current >= m) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}