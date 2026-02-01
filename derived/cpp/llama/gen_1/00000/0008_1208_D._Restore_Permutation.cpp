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
    vector<long long> ans(n);
    vector<bool> used(n + 1, false);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n; j > 0; --j) {
            if (used[j]) continue;
            long long sum = 0;
            for (int k = 0; k < i; ++k) {
                if (ans[k] < j) sum += ans[k];
            }
            if (sum == s[i]) {
                ans[i] = j;
                used[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}