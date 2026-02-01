#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

const int MAX_N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> arr(n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++) {
        arr[i][0] = i;
        arr[i][1] = 0;
    }

    for (int i = 0; i < q; i++) {
        int t, k, d;
        cin >> t >> k >> d;

        sort(arr.begin() + 1, arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        long long sum = 0;
        int count = 0;

        for (int j = 1; j <= n; j++) {
            if (arr[j][1] <= t) {
                if (count < k) {
                    sum += arr[j][0];
                    count++;
                    arr[j][1] = t + d;
                }
            }

            if (count == k) break;
        }

        if (count == k) {
            cout << sum << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}