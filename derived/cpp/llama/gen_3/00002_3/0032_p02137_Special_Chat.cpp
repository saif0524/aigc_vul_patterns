#include <iostream>
using namespace std;

int main() {
    int p;
    cin >> p;
    int ans = 0;
    int a[] = {10000, 5000, 1000, 500};
    for (int i = 0; i < 4; i++) {
        ans += (p / a[i]) * a[i];
        p %= a[i];
    }
    cout << ans << endl;
    return 0;
}