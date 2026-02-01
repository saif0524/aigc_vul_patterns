#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 300005;

int n, x1, x2;
int c[MAXN];
int idx[MAXN];

bool cmp(int a, int b) {
    return c[a] > c[b];
}

int main() {
    scanf("%d %d %d", &n, &x1, &x2);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        idx[i] = i;
    }
    sort(idx + 1, idx + n + 1, cmp);

    bool found = false;
    for (int k1 = 1; k1 <= n; k1++) {
        int k2 = 1;
        while (k1 + k2 <= n) {
            int sum1 = 0;
            for (int i = 1; i <= k1; i++) {
                sum1 += c[idx[i]];
            }
            if (sum1 >= x1) {
                int sum2 = 0;
                for (int i = k1 + 1; i <= k1 + k2; i++) {
                    sum2 += c[idx[i]];
                }
                if (sum2 >= x2) {
                    found = true;
                    printf("Yes\n");
                    printf("%d %d\n", k1, k2);
                    for (int i = 1; i <= k1; i++) {
                        printf("%d ", idx[i]);
                    }
                    printf("\n");
                    for (int i = k1 + 1; i <= k1 + k2; i++) {
                        printf("%d ", idx[i]);
                    }
                    printf("\n");
                    break;
                }
            }
            k2++;
        }
        if (found) {
            break;
        }
    }
    if (!found) {
        for (int k2 = 1; k2 <= n; k2++) {
            int k1 = 1;
            while (k1 + k2 <= n) {
                int sum2 = 0;
                for (int i = 1; i <= k2; i++) {
                    sum2 += c[idx[i]];
                }
                if (sum2 >= x2) {
                    int sum1 = 0;
                    for (int i = k2 + 1; i <= k1 + k2; i++) {
                        sum1 += c[idx[i]];
                    }
                    if (sum1 >= x1) {
                        found = true;
                        printf("Yes\n");
                        printf("%d %d\n", k1, k2);
                        for (int i = k2 + 1; i <= k1 + k2; i++) {
                            printf("%d ", idx[i]);
                        }
                        printf("\n");
                        for (int i = 1; i <= k2; i++) {
                            printf("%d ", idx[i]);
                        }
                        printf("\n");
                        break;
                    }
                }
                k1++;
            }
            if (found) {
                break;
            }
        }
    }
    if (!found) {
        printf("No\n");
    }
    return 0;
}