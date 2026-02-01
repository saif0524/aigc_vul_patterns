#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int MAX = 2e5 + 7;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int a = arr[0];
        for (int i = 1; i < n; i++) {
            a = gcd(a, arr[i]);
        }

        for (int i = 0; i < n; i++) {
            cout << a << " ";
        }
        cout << "\n";
    }

    return 0;
}