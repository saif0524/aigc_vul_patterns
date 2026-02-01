#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e4 + 10;

char s[MAXN];
int n, k, l, a[MAXN], b[MAXN], c[MAXN];

struct State {
    int cnt1, cnt2, step;
};

int main() {
    scanf("%d%d%d", &n, &k, &l);
    memset(s, '0', sizeof(s));
    for (int i = 1; i <= k; i++) {
        scanf("%d", &a[i]);
        s[a[i]] = '1';
    }
    for (int i = 1; i <= l; i++) {
        scanf("%d", &b[i]);
    }

    queue<State> q;
    memset(c, 0, sizeof(c));
    q.push({0, 0, 0});

    while (!q.empty()) {
        State now = q.front();
        q.pop();
        c[now.cnt1] = now.cnt2;
        for (int i = 1; i <= l; i++) {
            int t1 = now.cnt1, t2 = now.cnt2 + 1, v = b[i];
            char tmp[MAXN];
            memcpy(tmp, s, sizeof(s));
            for (int j = t1 + 1; j <= t1 + v; j++) {
                if (j > n) break;
                tmp[j] = (tmp[j] == '0') ? '1' : '0';
            }
            int x = 0;
            for (int j = 1; j <= n; j++) {
                if (tmp[j] != s[j]) x++;
            }
            if (x < n && !c[x]) {
                c[x] = t2;
                q.push({x, t2, now.step + 1});
            }
        }
    }

    if (c[n]) printf("%d\n", c[n]);
    else printf("-1\n");

    return 0;
}