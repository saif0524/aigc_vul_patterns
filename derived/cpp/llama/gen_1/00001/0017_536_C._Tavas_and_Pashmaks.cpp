#include <iostream>
#include <set>
#include <vector>

#define ll long long

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<ll, ll>> v(n);
    for (auto& p : v) {
        std::cin >> p.first >> p.second;
    }

    std::set<int> ans;
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                ll a = v[i].first * v[j].second;
                ll b = v[j].first * v[i].second;
                if (a >= b) {
                    continue;
                } else {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            ans.insert(i + 1);
        }
    }

    for (auto& p : ans) {
        std::cout << p << " ";
    }

    return 0;
}