#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    set<int> x, y;
    for (int i = 0; i < n; i++) {
        int mx = *max_element(a[i].begin(), a[i].end());
        x.insert(mx);
    }
    for (int j = 0; j < m; j++) {
        int mx = *max_element(a[0][j], a[n][j]);
        for (int i = 1; i < n; i++) {
            mx = max(mx, a[i][j]);
        }
        y.insert(mx);
    }

    vector<int> xSorted(x.begin(), x.end());
    vector<int> ySorted(y.begin(), y.end());
    sort(xSorted.begin(), xSorted.end());
    sort(ySorted.begin(), ySorted.end());

    set<int> used;
    vector<vector<int>> ans(n, vector<int>(m, 0));
    int xi = xSorted.size() - 1;
    int yi = ySorted.size() - 1;
    int bi = min(xi, yi);

    for (int i = 0; i <= bi; i++) {
        int curr = min(xSorted[xi], ySorted[yi]);
        ans[i][i] = curr;
        used.insert(curr);
        xi--;
        yi--;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] == 0) {
                int curr = *used.begin();
                while (used.find(curr) != used.end()) {
                    curr++;
                }
                ans[i][j] = curr;
                used.insert(curr);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}