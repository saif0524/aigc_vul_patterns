#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int n, a[N], b[N], c[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    int ans = n * 3;

    for (int u = 0; u <= n; ++u) {
        for (int v = 0; v <= n; ++v) {
            for (int w = 0; w <= n; ++w) {
                set<int> st;

                for (int i = 0; i < u; ++i) {
                    st.insert(a[i]);
                }

                for (int i = 0; i < v; ++i) {
                    st.insert(b[i]);
                }

                for (int i = 0; i < w; ++i) {
                    st.insert(c[i]);
                }

                bool all = true;

                for (int i = 0; i < n; ++i) {
                    if (!st.count(a[i])) {
                        all = false;
                        break;
                    }
                }

                for (int i = 0; i < n; ++i) {
                    if (!st.count(b[i])) {
                        all = false;
                        break;
                    }
                }

                for (int i = 0; i < n; ++i) {
                    if (!st.count(c[i])) {
                        all = false;
                        break;
                    }
                }

                if (all) {
                    ans = min(ans, u + v + w);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}