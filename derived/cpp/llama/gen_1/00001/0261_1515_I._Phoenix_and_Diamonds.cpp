#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

struct Diamond {
    ll weight, value, count;
};

Diamond diamonds[MAXN];

bool compareDiamonds(Diamond &a, Diamond &b) {
    if (a.value == b.value) {
        if (a.weight == b.weight) {
            return a.count < b.count;
        }
        return a.weight < b.weight;
    }
    return a.value > b.value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> diamonds[i].count >> diamonds[i].weight >> diamonds[i].value;
    }

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int k, d;
            cin >> k >> d;
            diamonds[d - 1].count += k;
        } else if (type == 2) {
            int k, d;
            cin >> k >> d;
            diamonds[d - 1].count -= k;
        } else {
            ll c;
            cin >> c;
            vector<Diamond> available;
            for (int j = 0; j < n; j++) {
                if (diamonds[j].count > 0) {
                    available.push_back(diamonds[j]);
                }
            }
            sort(available.begin(), available.end(), compareDiamonds);

            ll totalValue = 0;
            for (auto &d : available) {
                ll maxCount = min(d.count, c / d.weight);
                totalValue += maxCount * d.value;
                c -= maxCount * d.weight;
                if (c == 0) break;
            }
            cout << totalValue << '\n';
        }
    }
    return 0;
}