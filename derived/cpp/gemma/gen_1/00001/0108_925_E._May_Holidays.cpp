#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
    }

    vector<int> t(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    vector<int> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i];
    }

    vector<bool> on_vacation(n + 1, false);
    vector<vector<int>> subordinates(n + 1);
    for (int i = 2; i <= n; ++i) {
        subordinates[p[i]].push_back(i);
    }

    vector<int> displeased_count(m);

    for (int day = 0; day < m; ++day) {
        int employee_id = q[day];
        if (employee_id > 0) {
            on_vacation[employee_id] = true;
        } else {
            on_vacation[-employee_id] = false;
        }

        int displeased = 0;
        for (int i = 1; i <= n; ++i) {
            int vacationing_subordinates = 0;
            for (int sub : subordinates[i]) {
                if (on_vacation[sub]) {
                    vacationing_subordinates++;
                }
            }
            if (vacationing_subordinates > t[i] && !on_vacation[i]) {
                displeased++;
            }
        }
        displeased_count[day] = displeased;
    }

    for (int i = 0; i < m; ++i) {
        cout << displeased_count[i] << (i == m - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}