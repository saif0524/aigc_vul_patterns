#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void printPath(const vector<int>& path) {
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (n <= 4 || k < n - 1) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> path1, path2;
    path1.push_back(a);
    path2.push_back(c);

    bool found = false;
    for (int p = 1; p <= n; ++p) {
        if (p != a && p != b && p != c && p != d) {
            path1.push_back(p);
            path2.push_back(p);
        }
    }

    path1.push_back(b);
    path2.push_back(d);

    if (path1.size() > n || path2.size() > n) {
        cout << -1 << endl;
        return 0;
    }

    set<pair<int, int>> roads;
    for (int i = 0; i < path1.size() - 1; ++i) {
        int x = path1[i];
        int y = path1[i + 1];
        if (x > y) {
            swap(x, y);
        }
        roads.insert(make_pair(x, y));
    }

    for (int i = 0; i < path2.size() - 1; ++i) {
        int x = path2[i];
        int y = path2[i + 1];
        if (x > y) {
            swap(x, y);
        }
        roads.insert(make_pair(x, y));
    }

    if (roads.size() > k) {
        cout << -1 << endl;
    } else {
        printPath(path1);
        printPath(path2);
    }

    return 0;
}