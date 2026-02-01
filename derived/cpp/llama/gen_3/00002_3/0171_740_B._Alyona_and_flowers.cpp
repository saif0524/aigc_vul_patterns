#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    vector<vector<int>> sub(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &sub[i][0], &sub[i][1]);
        sub[i][0]--;
        sub[i][1]--;
    }

    int max_value = 0;
    for (int mask = 0; mask < (1 << m); ++mask) {
        vector<int> count(n, 0);
        for (int i = 0; i < m; ++i) {
            if ((mask >> i) & 1) {
                for (int j = sub[i][0]; j <= sub[i][1]; ++j) {
                    count[j]++;
                }
            }
        }

        int value = 0;
        for (int i = 0; i < n; ++i) {
            value += a[i] * count[i];
        }

        max_value = max(max_value, value);
    }

    printf("%d\n", max_value);

    return 0;
}