#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }

    bool can = false;
    int reach = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i].first > reach) {
            break;
        }
        reach = max(reach, arr[i].second);
        if (reach >= m) {
            can = true;
            break;
        }
    }

    cout << (can ? "YES" : "NO") << endl;

    return 0;
}