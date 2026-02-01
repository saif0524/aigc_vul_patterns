#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 15;

long double maxVolume = 0.0L;

void dfs(int n, int idx, int a[], int used[]) {
    if (used[0] > used[1] && used[1] > used[2] && used[2] > used[3] && used[3] > used[4] && used[3] > used[5]) {
        if (used[0] > 0 && used[1] > 0 && used[2] > 0 && used[3] > 0 && used[4] > 0 && used[5] > 0) {
            long double edge1 = (long double)used[0];
            long double edge2 = (long double)used[1];
            long double edge3 = (long double)used[2];
            long double edge4 = (long double)used[3];
            long double edge5 = (long double)used[4];
            long double edge6 = (long double)used[5];

            long double volume = (1.0L / 12.0L) * sqrtl(
                (edge1 * edge1 + edge2 * edge2 + edge3 * edge3 - edge4 * edge4) *
                (edge1 * edge1 + edge4 * edge4 + edge5 * edge5 - edge2 * edge2) *
                (edge2 * edge2 + edge4 * edge4 + edge6 * edge6 - edge3 * edge3) *
                (edge1 * edge1 + edge3 * edge3 + edge6 * edge6 - edge5 * edge5)
            );

            maxVolume = maxl(maxVolume, volume);
        }
    }

    for (int i = idx; i < n; ++i) {
        used[idx % 6]++;
        dfs(n, i + 1, a, used);
        used[idx % 6]--;
    }
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;

        int a[n];
        for (int i = 0; i < n; ++i) cin >> a[i];

        sort(a, a + n);

        int used[6] = {0};
        maxVolume = 0.0L;
        dfs(n, 0, a, used);

        cout << maxVolume << endl;
    }

    return 0;
}