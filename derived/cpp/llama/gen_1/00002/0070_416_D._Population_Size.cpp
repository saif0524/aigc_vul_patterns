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
    int l = 0;
    while (l < n) {
        int r = l + 1;
        while (r < n && (a[r] - a[r - 1] == a[l + 1] - a[l] || a[r] == -1 || a[r - 1] == -1 || a[l] == -1 || a[l + 1] == -1)) {
            r++;
        }
        ans++;
        l = r;
    }
    cout << ans << endl;
    return 0;
}