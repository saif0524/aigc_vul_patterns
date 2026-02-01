#include <iostream>
#include <set>
#include <utility>

using namespace std;

typedef long long int ll;

void solve() {
    ll n;
    cin >> n;

    multiset<pair<ll, ll>> s;

    while (n--) {
        ll start, duration;
        cin >> start >> duration;

        bool scheduled = false;
        ll free_start = 1;

        while (!s.empty()) {
            auto p = *s.begin();

            if (p.first <= free_start) {
                s.erase(s.begin());
                free_start = p.second + 1;
            }
            else {
                break;
            }
        }

        ll x;
        for (x = free_start; !scheduled; x++) {
            bool is_free = true;

            for (auto p : s) {
                if (x >= p.first && x < p.second + 1) {
                    is_free = false;
                    break;
                }
            }

            if (is_free) {
                ll y = x + duration - 1;

                bool is_range_free = true;
                auto it = s.upper_bound({x, 0ll});

                for (auto p : s) {
                    if (p.first <= x + duration && p.first >= x) {
                        is_range_free = false;
                        break;
                    }
                }

                if (is_range_free) {
                    s.insert({x, y});
                    scheduled = true;

                    cout << x << ' ' << y << '\n';
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}