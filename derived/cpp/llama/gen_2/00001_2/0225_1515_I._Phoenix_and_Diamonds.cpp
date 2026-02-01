#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Diamond {
    ll weight;
    ll value;
    ll count;
};

bool compareDiamonds(const Diamond& d1, const Diamond& d2) {
    if (d1.value != d2.value) {
        return d1.value > d2.value;
    } else if (d1.weight != d2.weight) {
        return d1.weight < d2.weight;
    }
    return false;
}

int main() {
    ll n, q;
    cin >> n >> q;

    vector<Diamond> diamonds(n);
    for (int i = 0; i < n; ++i) {
        cin >> diamonds[i].count >> diamonds[i].weight >> diamonds[i].value;
    }

    while (q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll k, d;
            cin >> k >> d;
            diamonds[d - 1].count += k;
        } else if (t == 2) {
            ll k, d;
            cin >> k >> d;
            diamonds[d - 1].count -= k;
        } else {
            ll c;
            cin >> c;

            vector<Diamond> diamondList;
            for (const auto& diamond : diamonds) {
                for (int i = 0; i < diamond.count; ++i) {
                    diamondList.push_back({diamond.weight, diamond.value, 1});
                }
            }

            sort(diamondList.begin(), diamondList.end(), compareDiamonds);

            ll value = 0;
            for (const auto& diamond : diamondList) {
                if (c >= diamond.weight) {
                    c -= diamond.weight;
                    value += diamond.value;
                } else {
                    break;
                }
            }

            cout << value << endl;
        }
    }

    return 0;
}