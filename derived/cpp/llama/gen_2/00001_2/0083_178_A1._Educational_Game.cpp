#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    for (int k = 1; k < n; k++) {
        ans += a[k - 1];
        cout << ans << endl;
    }

    return 0;
}