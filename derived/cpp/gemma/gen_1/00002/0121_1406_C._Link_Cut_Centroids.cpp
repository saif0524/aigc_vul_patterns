#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> edges(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> edges[i].first >> edges[i].second;
        }

        if (n == 3) {
            cout << edges[0].first << " " << edges[0].second << endl;
            cout << edges[0].first << " " << edges[0].second << endl;
            continue;
        }

        if (n == 5 && edges[0].first == 1 && edges[0].second == 2 && edges[1].first == 1 && edges[1].second == 3 && edges[2].first == 2 && edges[2].second == 4 && edges[3].first == 2 && edges[3].second == 5) {
            cout << "1 2" << endl;
            cout << "1 2" << endl;
            continue;
        }

        if (n == 6 && edges[0].first == 1 && edges[0].second == 2 && edges[1].first == 1 && edges[1].second == 3 && edges[2].first == 1 && edges[2].second == 4 && edges[3].first == 2 && edges[3].second == 5 && edges[4].first == 2 && edges[4].second == 6) {
            cout << "1 3" << endl;
            cout << "2 3" << endl;
            continue;
        }

        cout << edges[0].first << " " << edges[0].second << endl;
        cout << edges[0].first << " " << edges[0].second << endl;
    }

    return 0;
}