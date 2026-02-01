#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long a[n];
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ans += a[i] - a[j];
        }
    }

    cout << ans << endl;

    return 0;
}