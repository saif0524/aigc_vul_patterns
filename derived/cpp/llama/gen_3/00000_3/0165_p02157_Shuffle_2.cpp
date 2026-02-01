#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

ll n, q, k, d;

ll op(ll n, ll k, bool rev) {
    if (!rev) {
        if (k % 2 == 0) return k / 2 + n / 2;
        return k / 2;
    } else {
        if (k % 2 == 1) return k / 2 + n / 2;
        return k / 2;
    }
}

int main() {
    std::cin >> n >> q >> k >> d;

    std::vector<bool> ans;
    while (q--) {
        if (n == 2) {
            if (k == 2 && d == 1) {
                ans.push_back(1);
                break;
            }
            if (k == 1 && d == 2) {
                ans.push_back(0);
                break;
            }
            std::cout << -1 << std::endl;
            return 0;
        }
        if (d % 2) {
            if (k % 2) {
                ans.push_back(1);
                k = op(n, k, true);
                d = op(n, d, true);
            } else {
                ans.push_back(0);
                k = op(n, k, false);
                d = op(n, d, false);
            }
        } else {
            if (k % 2 == 0) {
                ans.push_back(0);
                k = op(n, k, false);
                d = op(n, d, false);
            } else {
                ans.push_back(1);
                k = op(n, k, true);
                d = op(n, d, true);
            }
        }
        n /= 2;
    }

    if (k != d) std::cout << -1 << std::endl;
    else for (auto it = ans.rbegin(); it != ans.rend(); it++) std::cout << *it << std::endl;

    return 0;
}