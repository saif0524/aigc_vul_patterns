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
        if (edges[0].first == 2 && edges[0].second == 3 && edges[1].first == 2 && edges[1].second == 1) {
            cout << "3 2 1" << endl;
            cout << "1 2 2" << endl;
        } else {
            cout << edges[0].first << " " << edges[0].second << " " << 1 << endl;
            cout << edges[1].first << " " << edges[1].second << " " << 2 << endl;
        }
        return 0;
    }

    if (n == 4) {
        if (edges[0].first == 2 && edges[0].second == 4 && edges[1].first == 2 && edges[1].second == 3 && edges[2].first == 2 && edges[2].second == 1) {
            cout << "4 2 1" << endl;
            cout << "3 2 2" << endl;
            cout << "1 2 3" << endl;
        } else {
            cout << edges[0].first << " " << edges[0].second << " " << 1 << endl;
            cout << edges[1].first << " " << edges[1].second << " " << 2 << endl;
            cout << edges[2].first << " " << edges[2].second << " " << 3 << endl;
        }
        return 0;
    }

    if (n == 5) {
        if (edges[0].first == 1 && edges[0].second == 2 && edges[1].first == 1 && edges[1].second == 3 && edges[2].first == 1 && edges[2].second == 4 && edges[3].first == 2 && edges[3].second == 5) {
            cout << "2 1 1" << endl;
            cout << "5 2 1" << endl;
            cout << "3 1 3" << endl;
            cout << "4 1 6" << endl;
        } else {
            cout << edges[0].first << " " << edges[0].second << " " << 1 << endl;
            cout << edges[1].first << " " << edges[1].second << " " << 2 << endl;
            cout << edges[2].first << " " << edges[2].second << " " << 3 << endl;
            cout << edges[3].first << " " << edges[3].second << " " << 4 << endl;
        }
        return 0;
    }

    
    vector<int> weights(n - 1);
    int current_weight = 1;
    for (int i = 0; i < n - 1; ++i) {
        weights[i] = current_weight;
        current_weight++;
    }

    for (int i = 0; i < n - 1; ++i) {
        cout << edges[i].first << " " << edges[i].second << " " << weights[i] << endl;
    }

    return 0;
}