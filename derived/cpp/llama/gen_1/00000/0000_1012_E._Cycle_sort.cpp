#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.begin(), b.end());

    if (a == b) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> p(n, -1);
    for (int i = 0; i < n; i++) {
        int j = i;
        while (p[j] == -1) {
            p[j] = i;
            j = find(a.begin(), a.end(), b[j]) - a.begin();
        }
        if (p[i] != i) {
            swap(a[i], a[j]);
        }
    }

    vector<vector<int>> cycles;
    for (int i = 0; i < n; i++) {
        if (p[i] != i) {
            vector<int> cycle;
            int j = i;
            while (j != i) {
                cycle.push_back(j + 1);
                j = find(a.begin(), a.end(), b[j]) - a.begin();
            }
            cycle.push_back(i + 1);
            cycles.push_back(cycle);
        }
    }

    int sum = 0;
    for (auto& cycle : cycles) {
        sum += cycle.size();
    }

    if (sum > s) {
        cout << -1 << endl;
        return 0;
    }

    cout << cycles.size() << endl;
    for (auto& cycle : cycles) {
        cout << cycle.size() << endl;
        for (int j : cycle) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}