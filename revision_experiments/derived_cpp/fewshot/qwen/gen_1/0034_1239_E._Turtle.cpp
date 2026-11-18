#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> path_a, path_b;
    int sum =0, i = 0, j = 0;
    while (i < n && j < n) {
        if (a[i] <= b[j]) {
            path_a.push_back(a[i]);
            i++;
        } else {
            path_b.push_back(b[j]);
            j++;
        }
    }

    while (i < n) path_a.push_back(a[i++]);
    while (j < n) path_b.push_back(b[j++]);

    reverse(path_b.begin(), path_b.end());

    for (int i = 0; i < n; ++i) {
        if (path_a.empty()) {
            cout << path_b.back() << " ";
            path_b.pop_back();
        } else if (path_b.empty()) {
            cout << path_a.back() << " ";
            path_a.pop_back();
        } else if (path_a.back() <= path_b.back()) {
            cout << path_a.back() << " ";
            path_a.pop_back();
        } else {
            cout << path_b.back() << " ";
            path_b.pop_back();
        }
    }
    cout << "\n";

    for (int i = 0; i < n; ++i) {
        if (path_b.empty()) {
            cout << path_a.back() << " ";
            path_a.pop_back();
        } else if (path_a.empty()) {
            cout << path_b.back() << " ";
            path_b.pop_back();
        } else if (path_a.back() <= path_b.back()) {
            cout << path_a.back() << " ";
            path_a.pop_back();
        } else {
            cout << path_b.back() << " ";
            path_b.pop_back();
        }
    }
    cout << "\n";

    return 0;
}