#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 55;

int n;
int a[MAXN][MAXN];
pair<int, int> b[MAXN];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        b[i].first = 0;
        for (int j = 1; j <= n; j++) {
            b[i].first = max(b[i].first, a[i][j]);
        }
        b[i].second = i;
    }

    sort(b + 1, b + 1 + n);

    for (int i = 1; i <= n; i++) {
        cout << n - b[i].first + 1 << " ";
    }

    return 0;
}