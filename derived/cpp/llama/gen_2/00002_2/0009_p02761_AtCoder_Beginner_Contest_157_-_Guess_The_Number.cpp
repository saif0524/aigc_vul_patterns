#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> constraints(m);
    for (int i = 0; i < m; i++) {
        cin >> constraints[i].first >> constraints[i].second;
    }

    sort(constraints.begin(), constraints.end());

    int low = pow(10, n - 1);
    int high = pow(10, n);

    for (int num = low; num < high; num++) {
        string str = to_string(num);
        bool valid = true;
        for (int i = 0; i < m; i++) {
            if (str[constraints[i].first - 1] - '0' != constraints[i].second) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << num << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}