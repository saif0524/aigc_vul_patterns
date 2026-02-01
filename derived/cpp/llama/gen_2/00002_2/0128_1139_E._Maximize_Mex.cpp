#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

const int N = 5005;

int n, m, d;
int p[N], c[N];
int cnt[N][N];
int ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        cnt[c[i]][p[i]]++;
    }
    cin >> d;
    vector<int> k(d);
    for (int i = 0; i < d; i++) {
        cin >> k[i];
    }

    for (int i = 0; i < d; i++) {
        for (int j = 1; j <= m; j++) {
            cnt[j][p[k[i]]]--;
        }
        int res = 0;
        while (true) {
            bool flag = true;
            set<int> s;
            for (int j = 1; j <= m; j++) {
                int x = -1;
                for (int k = 0; k <= res; k++) {
                    if (cnt[j][k] > 0) {
                        x = k;
                        break;
                    }
                }
                if (x == -1) {
                    flag = false;
                    break;
                }
                s.insert(x);
            }
            if (flag && s.size() == m) {
                res++;
            } else {
                break;
            }
        }
        ans[i] = res;
    }

    for (int i = 0; i < d; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}