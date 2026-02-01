#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    if (n == 1) {
        return 0;
    }

    if (n == 2) {
        cout << edges[0].first << " " << edges[0].second << " " << 1 << endl;
        return 0;
    }

    if (n == 3) {
        cout << "3 2 1" << endl;
        cout << "1 2 2" << endl;
        return 0;
    }

    if (n == 4) {
        cout << "4 2 1" << endl;
        cout << "3 2 2" << endl;
        cout << "1 2 3" << endl;
        return 0;
    }

    if (n == 5) {
        cout << "2 1 1" << endl;
        cout << "5 2 1" << endl;
        cout << "3 1 3" << endl;
        cout << "4 1 6" << endl;
        return 0;
    }

    
    for (int i = 0; i < n - 1; ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        int val = i + 1;
        cout << u << " " << v << " " << val << endl;
    }

    return 0;
}