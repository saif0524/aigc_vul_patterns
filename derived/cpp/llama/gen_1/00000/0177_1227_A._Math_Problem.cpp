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

        int mxl = *max_element(l.begin(), l.end());
        int mnr = *min_element(r.begin(), r.end());

        cout << max(0, mxl - mnr) << endl;
    }

    return 0;
}