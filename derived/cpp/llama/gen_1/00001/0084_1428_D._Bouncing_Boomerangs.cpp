#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100005;

int n;
int a[MAX_N];
int curRow[MAX_N];
int ans[MAX_N][2];
int ansCount;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int totalHits = 0;
    for (int i = 1; i <= n; ++i) {
        totalHits += a[i];
    }

    if (totalHits > 2 * n) {
        cout << -1 << endl;
        return;
    }

    fill(curRow + 1, curRow + n + 1, 1);

    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) continue;
        if (a[i] == 1) {
            ans[++ansCount][0] = curRow[i];
            ans[ansCount][1] = i;
            curRow[i] = min(curRow[i] + 1, n);
        } else if (a[i] == 2) {
            ans[++ansCount][0] = curRow[i];
            ans[ansCount][1] = i;
            ans[++ansCount][0] = min(curRow[i] + 1, n);
            ans[ansCount][1] = i;
            curRow[i] = min(curRow[i] + 2, n);
        } else {
            ans[++ansCount][0] = curRow[i];
            ans[ansCount][1] = i;
            ans[++ansCount][0] = min(curRow[i] + 1, n);
            ans[ansCount][1] = i;
            int firstrow = curRow[i];
            int secondrow = min(curRow[i] + 1, n);
            int nextCol = i + 1;
            while (nextCol <= n && a[nextCol] == 0) nextCol++;

            if (nextCol > n || curRow[nextCol] > n) {
                cout << -1 << endl;
                return;
            }

            ans[++ansCount][0] = curRow[nextCol];
            ans[ansCount][1] = nextCol;
            curRow[nextCol] = min(curRow[nextCol] + 1, n);

            curRow[i] = min(curRow[i] + 2, n);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (curRow[i] > n) {
            cout << -1 << endl;
            return;
        }
    }

    cout << ansCount << endl;
    for (int i = 1; i <= ansCount; ++i) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}