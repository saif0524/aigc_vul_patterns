#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> operations(m, vector<int>(4));
    for (int i = 0; i < m; i++) {
        cin >> operations[i][0] >> operations[i][1] >> operations[i][2] >> operations[i][3];
        operations[i][1]--;
        operations[i][2]--;
    }

    vector<long long> arr(n, INT_MIN);
    bool ok = true;

    for (int i = m - 1; i >= 0; i--) {
        int t = operations[i][0];
        int l = operations[i][1];
        int r = operations[i][2];
        int d = operations[i][3];

        if (t == 1) {
            for (int j = l; j <= r; j++) {
                if (arr[j] != INT_MIN) {
                    arr[j] -= d;
                }
            }
        } else {
            long long maxVal = INT_MIN;
            for (int j = l; j <= r; j++) {
                if (arr[j] == INT_MIN) {
                    arr[j] = d;
                }
                maxVal = max(maxVal, arr[j]);
            }
            if (maxVal != d) {
                ok = false;
                break;
            }
        }
    }

    if (!ok) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        if (arr[i] == INT_MIN) {
            arr[i] = 0;
        }
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}