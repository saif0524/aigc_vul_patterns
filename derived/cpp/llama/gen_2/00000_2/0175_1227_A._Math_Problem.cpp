#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> l(n), r(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
        }

        int l_max = *max_element(l.begin(), l.end());
        int r_min = *min_element(r.begin(), r.end());

        cout << max(0, l_max - r_min) << endl;
    }

    return 0;
}