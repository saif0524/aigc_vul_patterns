#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<int> v, u;
    set<pair<int, int>> roads;

    if (n == 4 && (a == c && b == d || a == d && b == c)) {
        cout << "-1" << endl;
        return 0;
    }

    if (k < n - 1) {
        cout << "-1" << endl;
        return 0;
    }

    v.push_back(a);
    for (int i = 1; i <= n; i++) {
        if (i != a && i != b) {
            v.push_back(i);
        }
    }
    v.push_back(b);

    if (c == a) {
        u.push_back(c);
        for (int i = 1; i <= n; i++) {
            if (i != c && i != d) {
                u.push_back(i);
            }
        }
        u.push_back(d);
    } else if (c == b) {
        reverse(v.begin(), v.end());
        u.push_back(c);
        for (int i = 1; i <= n; i++) {
            if (i != c && i != d) {
                u.push_back(i);
            }
        }
        u.push_back(d);
    } else {
        bool flag = false;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == c) {
                u.push_back(c);
                for (int j = i + 1; j < v.size(); j++) {
                    u.push_back(v[j]);
                }
                for (int j = 0; j < i; j++) {
                    u.push_back(v[j]);
                }
                flag = true;
                break;
            }
        }
        if (!flag) {
            u.push_back(c);
            for (int i = 1; i <= n; i++) {
                if (i != c && i != d) {
                    u.push_back(i);
                }
            }
            u.push_back(d);
        }
    }

    for (int i = 0; i < v.size() - 1; i++) {
        roads.insert(make_pair(min(v[i], v[i + 1]), max(v[i], v[i + 1])));
    }

    for (int i = 0; i < u.size() - 1; i++) {
        roads.insert(make_pair(min(u[i], u[i + 1]), max(u[i], u[i + 1])));
    }

    if (roads.size() <= k) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < u.size(); i++) {
            cout << u[i] << " ";
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}