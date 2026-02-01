#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;
pair<int, int> a[N];
int b[N], c[N], ans1[N], ans2[N];
set<int> st[N];

bool check() {
    for (int i = 1; i <= n; i++) b[i] = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = a[i].first; j <= a[i].second; j++) {
            if (b[j] == -1 && st[j].empty()) {
                b[j] = i;
                ans1[i] = j;
                break;
            }
        }
        for (auto x : st[i]) {
            st[x].erase(i);
        }
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        for (int j = a[i].first; j <= a[i].second; j++) {
            st[j].insert(i);
        }
    }
    if (check()) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) cout << ans1[i] << ' ';
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = a[i].first; j <= a[i].second; j++) {
                st[j].insert(i);
            }
        }
        int_embedding:
        for (int i = 1; i <= n; i++) {
            for (int j = a[i].first; j <= a[i].second; j++) {
                if (st[j].size() > 1) {
                    b[j] = i;
                    ans1[i] = j;
                    for (auto x : st[i]) {
                        st[x].erase(i);
                    }
                    goto end_loop;
                }
            }
        }
        end_loop:
        for (int i = 1; i <= n; i++) c[i] = -1;
        for (int i = 1; i <= n; i++) {
            if (ans1[i] == 0) {
                for (int j = a[i].first; j <= a[i].second; j++) {
                    if (c[j] == -1) {
                        c[j] = i;
                        ans1[i] = j;
                        break;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = a[i].first; j <= a[i].second; j++) {
                st[j].insert(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = a[i].first; j <= a[i].second; j++) {
                if (st[j].size() > 1) {
                    if (b[j] != i && c[j] != i) {
                        ans2[i] = j;
                        ans2[b[j]] = ans1[i];
                        goto done;
                    }
                }
            }
        }
        done:
        cout << "NO\n";
        for (int i = 1; i <= n; i++) cout << ans1[i] << ' ';
        cout << '\n';
        for (int i = 1; i <= n; i++) cout << ans2[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}