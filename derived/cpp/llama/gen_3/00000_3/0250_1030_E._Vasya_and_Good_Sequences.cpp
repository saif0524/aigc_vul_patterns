#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        int temp = a[i];
        while (temp) {
            cnt[i] += temp & 1;
            temp >>= 1;
        }
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        int odd = 0, even = 0;
        for (int j = i; j < n; j++) {
            if (cnt[j] % 2 == 1) {
                odd++;
            } else {
                even++;
            }
            if (odd % 2 == 0 && even % 2 == 0) {
                res++;
            }
        }
    }

    cout << res << endl;

    return 0;
}