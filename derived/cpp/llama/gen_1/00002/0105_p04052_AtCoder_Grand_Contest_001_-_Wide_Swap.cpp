#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

int n, k, p[MAXN], pos[MAXN];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        pos[p[i]] = i;
    }

    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        if (dq.empty() || dq.back() + k < i) {
            dq.push_back(i);
            p[pos[i]] = i;
        } else {
            dq.push_front(i);
            p[pos[i]] = dq.front();
            dq.pop_front();
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", p[i]);
    }

    return 0;
}