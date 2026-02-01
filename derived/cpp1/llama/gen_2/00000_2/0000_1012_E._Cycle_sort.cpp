#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());

    vector<vector<int>> cycles;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] != sorted_a[i]) {
            cnt++;
        }
    }

    if (cnt > s) {
        cout << "-1\n";
        return 0;
    }

    vector<int> p(n, -1);
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (p[j] == -1) {
            p[j] = i;
            j = distance(sorted_a.begin(), find(a.begin(), a.end(), sorted_a[j]));
        }
        if (j != i) {
            vector<int> cycle;
            while (j != i) {
                cycle.push_back(j + 1);
                p[j] = -1;
                j = distance(sorted_a.begin(), find(a.begin(), a.end(), sorted_a[j]));
            }
            cycle.push_back(i + 1);
            cycles.push_back(cycle);
            for (int ind : cycle) {
                p[ind - 1] = -1;
            }
        }
    }

    int q = cycles.size();
    cout << q << "\n";
    for (auto cycle : cycles) {
        cout << cycle.size() << "\n";
        for (int ind : cycle) {
            cout << ind << " ";
        }
        cout << "\n";
    }

    return 0;
}