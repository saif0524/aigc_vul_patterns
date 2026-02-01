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
            int j = 0;
            while (j < n - 1) {
                if (h[j] < h[j + 1]) {
                    h[j]++;
                    pos = j + 1;
                    break;
                }
                j++;
            }
            if (j == n - 1) {
                pos = -1;
                break;
            }
        }
        cout << pos << endl;
    }
    return 0;
}