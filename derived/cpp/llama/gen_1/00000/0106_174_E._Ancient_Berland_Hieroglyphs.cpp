#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 5;

int n, m;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<int> idx(1000001, -1);
    for (int i = 0; i < m; i++) {
        idx[b[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int len = 0;
        int pos = i;
        for (int j = 0; j < n; j++) {
            if (idx[a[pos]] == -1) {
                break;
            }
            len++;
            pos = (pos + 1) % n;
            int nextPos = idx[a[pos]];
            while (nextPos < idx[a[pos - 1]] && nextPos != -1) {
                nextPos = idx[b[nextPos + 1]];
            }
            if (nextPos == -1) {
                break;
            }
            idx[a[pos - 1]] = nextPos;
        }
        ans = max(ans, len);
    }

    cout << ans << '\n';

    return 0;
}