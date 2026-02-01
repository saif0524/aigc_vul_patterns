#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 105;

int n, m;
bitset<MAX_N> bulbs;
bitset<MAX_N> buttons[MAX_N];

void pressButton(int i) {
    bulbs |= buttons[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        for (int j = 0; j < k; ++j) {
            int bulb;
            cin >> bulb;
            buttons[i].set(bulb);
        }
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        bulbs.reset();

        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) != 0) {
                pressButton(i);
            }
        }

        if (bulbs.count() == m) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}