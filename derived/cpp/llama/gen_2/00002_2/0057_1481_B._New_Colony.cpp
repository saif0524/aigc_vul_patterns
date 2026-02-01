#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }

        int pos = 0;
        for (int i = 0; i < k; i++) {
            int curr = 0;
            while (curr < n - 1 && h[curr] >= h[curr + 1]) {
                curr++;
            }

            if (curr == n - 1) {
                pos = -1;
                break;
            }

            h[curr]++;
        }

        cout << pos << endl;
    }

    return 0;
}