#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> cnt(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt[j] += a[i][j] - '0';
        }
    }

    int nhalf = ceil(n / 2.0);
    vector<int> res(m, 0);
    for (int i = 0; i < m; i++) {
        if (cnt[i] >= nhalf) {
            res[i] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << res[i];
    }
    cout << endl;

    return 0;
}