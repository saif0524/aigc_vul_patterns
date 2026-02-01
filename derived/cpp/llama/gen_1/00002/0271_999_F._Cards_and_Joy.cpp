#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

const int MAX_N = 505;
const int MAX_K = 11;
const int MAX_C = 100005;

int n, k;
int c[MAX_N * MAX_K];
int f[MAX_N];
int h[MAX_K];
int count[MAX_N];
bitset<MAX_N * MAX_K> used;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n * k; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> h[i];
    }

    vector<int> p(n * k);
    for (int i = 0; i < n * k; i++) {
        p[i] = i;
    }

    sort(p.begin(), p.end(), [&](int x, int y) {
        int cx = 0, cy = 0;
        for (int i = 0; i < n; i++) {
            if (c[x] == f[i]) cx++;
            if (c[y] == f[i]) cy++;
        }
        return cx > cy;
    });

    int ans = 0;
    for (int i = 0; i < n * k; i++) {
        if (used[i]) continue;
        for (int j = 0; j < n; j++) {
            if (c[p[i]] == f[j] && count[j] < k) {
                count[j]++;
                ans += h[count[j]];
                used[i] = 1;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}