#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

const int MAX_N = 7007;

int next(int u, int v, int n) {
    return (u + v) % n;
}

int check(vector<int> &a, vector<int> &b, int u, int n) {
    vector<bool> used(MAX_N, false);
    used[u] = true;
    for (int k = 0; k < 2; k++) {
        int v = u;
        while (true) {
            bool found = false;
            for (int i = 0; i < a.size(); i++) {
                int t = next(v, a[i], n);
                if (!used[t]) {
                    used[t] = true;
                    v = t;
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
        }
        swap(a, b);
    }
    if (used[0]) {
        return 1;
    } else if (used[u]) {
        return 0;
    } else {
        return 2;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a, b;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    vector<int> r(n);
    for (int i = 1; i < n; i++) {
        r[i] = check(a, b, i, n);
    }
    for (int i = 1; i < n; i++) {
        if (r[i] == 1) {
            cout << "Win ";
        } else if (r[i] == 0) {
            cout << "Lose ";
        } else {
            cout << "Loop ";
        }
    }
    cout << endl;
    for (int i = 0; i < a.size(); i++) {
        swap(a[i], b[i]);
    }
    r.clear();
    r.resize(n);
    for (int i = 1; i < n; i++) {
        r[i] = check(b, a, i, n);
    }
    for (int i = 1; i < n; i++) {
        if (r[i] == 1) {
            cout << "Win ";
        } else if (r[i] == 0) {
            cout << "Lose ";
        } else {
            cout << "Loop ";
        }
    }
    cout << endl;
    return 0;
}