#include <bits/stdc++.h>
using namespace std;

const int MAXP = 17;

char str[100005];
int A[MAXP][MAXP];

int n, p;
vector<int> pos[MAXP];

bool canRemove(int c) {
    int m = pos[c].size();
    for (int i = 0; i < m; i++) {
        int p1 = pos[c][i];
        if (p1 == 0 || p1 == n - 1) continue;
        if (str[p1 - 1] == str[p1 + 1]) continue;
        int c1 = str[p1 - 1] - 'a', c2 = str[p1 + 1] - 'a';
        if (A[c1][c2] == 0) return false;
    }
    return true;
}

int maskToArr(int mask, int arr[]) {
    int idx = 0;
    for (int i = 0; i < p; i++) {
        if ((mask & (1 << i)) > 0) {
            arr[idx++] = i;
        }
    }
    return idx;
}

int checkMask(int mask) {
    int arr[MAXP], len;
    len = maskToArr(mask, arr);
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = 0; j < len; j++) {
            if (str[i] - 'a' == arr[j]) {
                ok = true;
                break;
            }
        }
        if (!ok) return n + 1;
        for (int j = i + 1; j < n; j++) {
            if (str[j] == str[i]) break;
            bool ok2 = false;
            for (int k = 0; k < len; k++) {
                if (str[j] - 'a' == arr[k]) {
                    ok2 = true;
                    break;
                }
            }
            if (!ok2) return n + 1;
            int c1 = str[i] - 'a', c2 = str[j] - 'a';
            if (A[c1][c2] == 0) return n + 1;
        }
    }
    int cnt[MAXP] = {0};
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = 0; j < len; j++) {
            if (str[i] - 'a' == arr[j]) {
                ok = true;
                break;
            }
        }
        if (ok) cnt[str[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < p; i++) ans += cnt[i];
    return ans;
}

int main() {
    scanf("%d%d", &n, &p);
    scanf("%s", str);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        pos[str[i] - 'a'].push_back(i);
    }
    int ans = n;
    for (int mask = 0; mask < (1 << p); mask++) {
        int tmp = checkMask(mask);
        if (tmp != n + 1) ans = min(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}