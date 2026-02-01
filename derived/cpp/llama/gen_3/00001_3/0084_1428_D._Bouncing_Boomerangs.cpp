#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> targetRow(n, -1), targetCol(n, -1);
    int cnt = 0;
    for (int col = 0; col < n; ++col) {
        if (a[col] == 0) continue;
        if (a[col] == 1) {
            for (int row = 0; row < n; ++row) {
                if (targetRow[row] < 1) {
                    targetRow[row]++;
                    targetCol[col] = row;
                    cnt++;
                    break;
                }
            }
        }
        else if (a[col] == 2) {
            int row = n - 1;
            while (row >= 0 && (targetRow[row] > 0 || targetCol[col] == row)) row--;
            if (row < 0) {
                cout << "-1\n";
                return;
            }
            targetRow[row]++;
            targetCol[col] = row;
            cnt++;

            row = n - 1;
            while (row >= 0 && (targetRow[row] > 0 || targetCol[col] == row)) row--;
            if (row < 0) {
                cout << "-1\n";
                return;
            }
            targetRow[row]++;
            cnt++;
        }
        else if (a[col] == 3) {
            int row = n - 1;
            while (row >= 0 && (targetRow[row] > 0 || targetCol[col] == row)) row--;
            if (row < 0) {
                cout << "-1\n";
                return;
            }
            targetRow[row]++;
            targetCol[col] = row;
            cnt++;

            row = n - 1;
            while (row >= 0 && (targetRow[row] > 0 || targetCol[col] == row)) row--;
            if (row < 0) {
                cout << "-1\n";
                return;
            }
            targetRow[row]++;
            cnt++;

            int colMin = min(col, n - 1 - col), colMax = max(col, n - 1 - col);
            bool flag = true;
            for (int i = colMin; i <= colMax; ++i) {
                if (a[i] == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "-1\n";
                return;
            }
            for (int i = colMin; i <= colMax; ++i) {
                if (a[i] == 1) {
                    targetCol[i] = targetCol[col];
                    break;
                }
            }
            cnt++;
        }
    }
    cout << cnt << '\n';
    vector<pair<int, int>> ans;
    for (int col = 0; col < n; ++col) {
        if (targetCol[col] != -1) {
            ans.emplace_back(targetCol[col] + 1, col + 1);
        }
    }
    for (auto [row, col] : ans) {
        cout << row << ' ' << col << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}