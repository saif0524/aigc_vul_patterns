#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][0]--;
        a[i][1]--;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                if (a[k][0] == i || a[k][1] == i || a[k][0] == j || a[k][1] == j) {
                    cnt++;
                }
            }
            if (cnt >= p) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}