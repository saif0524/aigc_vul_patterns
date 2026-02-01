#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 200005;

int n, k, a, b, q;
int orders[maxn];

void update(int day, int numOrders) {
    orders[day] += numOrders;
}

int calculateMaxFilledOrders(int repairStartDay) {
    int maxFilledOrders = 0;

    for (int day = 1; day <= n; day++) {
        if (day < repairStartDay) {
            maxFilledOrders += min(orders[day], b);
        } else if (day >= repairStartDay && day < repairStartDay + k) {
            // No production during repair
            continue;
        } else {
            maxFilledOrders += min(orders[day], a);
        }
    }

    return maxFilledOrders;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> a >> b >> q;

    while (q--) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int day, numOrders;
            cin >> day >> numOrders;
            update(day, numOrders);
        } else {
            int repairStartDay;
            cin >> repairStartDay;
            cout << calculateMaxFilledOrders(repairStartDay) << '\n';
        }
    }

    return 0;
}