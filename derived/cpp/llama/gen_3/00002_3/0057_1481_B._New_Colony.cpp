#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        vector<int> h(n);
        for (int j = 0; j < n; j++) {
            cin >> h[j];
        }
        int pos = 0;
        for (int j = 0; j < k; j++) {
            int curr = 0;
            while (curr < n - 1) {
                if (h[curr] < h[curr + 1]) {
                    h[curr]++;
                    pos = curr + 1;
                    break;
                }
                curr++;
            }
            if (curr == n - 1) {
                pos = -1;
                break;
            }
        }
        cout << pos << endl;
    }
    return 0;
}