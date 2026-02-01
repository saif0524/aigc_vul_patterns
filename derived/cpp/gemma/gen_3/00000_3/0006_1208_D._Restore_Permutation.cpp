#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> p(n);
    vector<bool> used(n + 1, false);

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!used[j]) {
                long long sum_before = 0;
                for (int k = 0; k < i; ++k) {
                    if (p[k] < j) {
                        sum_before += p[k];
                    }
                }
                if (sum_before == s[i]) {
                    p[i] = j;
                    used[j] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}