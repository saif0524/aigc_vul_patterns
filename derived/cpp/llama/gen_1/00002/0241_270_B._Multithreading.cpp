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
    int ans = 0;
    vector<bool> f(n + 1);
    for (int i = 0; i < n; i++) {
        f[a[i]] = true;
        if (i + 1 > a[i]) break;
        ans++;
        for (int j = 0; j <= i - a[i]; j++) {
            f[j + 1] = false;
        }
    }
    cout << ans << endl;
    return 0;
}