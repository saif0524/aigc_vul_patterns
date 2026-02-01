#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i];
    }

    for (int i = 0; i < m; ++i) {
        int qi = q[i];
        vector<int> temp_a = a;
        for (int j = 0; j < 2 * n - qi; ++j) {
            int start = j * 2 * qi + 1;
            int end = min((j + 1) * 2 * qi, 2 * n) - 1;
            reverse(temp_a.begin() + start, temp_a.begin() + end + 1);
        }

        long long inversions = 0;
        for (int j = 0; j < 2 * n; ++j) {
            for (int k = j + 1; k < 2 * n; ++k) {
                if (temp_a[j] > temp_a[k]) {
                    inversions++;
                }
            }
        }

        cout << inversions << endl;
        a = temp_a;
    }

    return 0;
}