#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (k % 2 == 1) {
            int d = *max_element(a.begin(), a.end());
            for (int i = 0; i < n; i++) {
                a[i] = d - a[i];
            }
        } else if (k > 0) {
            int d = *max_element(a.begin(), a.end());
            int min_val = *min_element(a.begin(), a.end());
            if (d - min_val!= 0) {
                for (int i = 0; i < n; i++) {
                    a[i] = d - a[i];
                }
                for (int i = 0; i < n; i++) {
                    a[i] = d - a[i];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}