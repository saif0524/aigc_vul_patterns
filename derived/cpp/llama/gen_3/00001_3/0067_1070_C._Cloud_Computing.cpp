#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int N = 1e6 + 10;
const ll INF = 1e18;

struct Plan {
    int l, r, c, p;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;

    vector<Plan> plans(m);
    for (int i = 0; i < m; i++) {
        cin >> plans[i].l >> plans[i].r >> plans[i].c >> plans[i].p;
    }

    vector<vector<pii>> events(n + 1);
    for (int i = 0; i < m; i++) {
        events[plans[i].l - 1].push_back({plans[i].c, plans[i].p});
        events[plans[i].r].push_back({-plans[i].c, -plans[i].p});
    }

    ll ans = 0;
    multiset<pii> st;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        for (auto& p : events[i]) {
            if (p.first > 0) {
                st.insert({p.second, p.first});
                cur += p.first;
            } else {
                auto it = st.find({-p.second, -p.first});
                if (it!= st.end()) {
                    st.erase(it);
                    cur += p.first;
                }
            }
        }

        int need = min(k, cur);
        ll cost = 0;
        while (need > 0 &&!st.empty()) {
            auto it = st.begin();
            int take = min(need, it->second);
            need -= take;
            cost += (ll)take * it->first;
            if (take < it->second) {
                st.erase(it);
                st.insert({it->first, it->second - take});
            }
        }
        ans += cost;
    }

    cout << ans << '\n';

    return 0;
}