#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    int ans = 1e9;

    if (even == 0 || odd == 0) {
        ans = min(ans, a[0]);
    } else if (even == n || odd == n) {
        ans = min(ans, a[n-1]);
    }

    vector<int> evenNums, oddNums;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            evenNums.push_back(a[i]);
        } else {
            oddNums.push_back(a[i]);
        }
    }

    if (odd > even + 1) {
        int tmp = 0;
        for (int i = 0; i < odd - (even + 1); i++) {
            tmp += a[i];
        }
        ans = min(ans, tmp);
    }

    if (even > odd + 1) {
        int tmp = 0;
        for (int i = 0; i < even - (odd + 1); i++) {
            tmp += a[i];
        }
        ans = min(ans, tmp);
    }

    if (even == odd || abs(even - odd) == 1) {
        ans = 0;
    }

    cout << ans << endl;

    return 0;
}