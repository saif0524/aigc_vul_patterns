#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;

    vector<int> demand(n + 1, 0);
    vector<int> supply_before(n + 1, b);
    vector<int> supply_after(n + 1, a);

    for (int i = 0; i < q; i++) {
        int query_type;
        cin >> query_type;

        if (query_type == 1) {
            int di, ai;
            cin >> di >> ai;
            demand[di] += ai;
        } else {
            int pi;
            cin >> pi;

            int total = 0;
            for (int j = 1; j < pi; j++) {
                total += min(demand[j], supply_before[j]);
            }

            for (int j = pi + k; j <= n; j++) {
                total += min(demand[j], supply_after[j]);
            }

            cout << total << endl;
        }
    }

    return 0;
}