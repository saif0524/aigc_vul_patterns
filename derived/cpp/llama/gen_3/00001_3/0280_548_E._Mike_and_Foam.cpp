#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
const int M = 5e5 + 5;

int n, q;
int a[N];
int cnt[M];
vector<int> divs[M];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                divs[j].push_back(i);
                if (j * j!= a[i]) {
                    divs[a[i] / j].push_back(i);
                }
            }
        }
    }

    set<int> st;
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        if (st.find(x)!= st.end()) {
            st.erase(x);
        } else {
            st.insert(x);
        }

        int ans = 0;
        for (int j = 1; j <= n; j++) {
            cnt[j] = 0;
        }

        for (auto it : st) {
            for (auto d : divs[a[it]]) {
                if (st.find(d)!= st.end()) {
                    cnt[a[d]]++;
                }
            }
        }

        for (auto it : st) {
            for (auto d : divs[a[it]]) {
                if (st.find(d)!= st.end() && d < it) {
                    ans += cnt[a[d]];
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}