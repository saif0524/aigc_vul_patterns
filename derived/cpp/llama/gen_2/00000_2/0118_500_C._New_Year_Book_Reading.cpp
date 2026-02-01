#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 505;

int n, m;
int w[MAXN];
int b[MAXN];
int cnt[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b[i]--;
        cnt[b[i]]++;
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    sort(p.begin(), p.end(), [](int x, int y) {
        return cnt[x] > cnt[y];
    });
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int id = -1;
        for (int j = 0; j < n; j++) {
            if (p[j] == b[i]) {
                id = j;
                break;
            }
        }
        for (int j = 0; j < id; j++) {
            ans += w[p[j]];
        }
        swap(p[id], p[n - 1]);
        n--;
    }
    cout << ans << endl;
    return 0;
}