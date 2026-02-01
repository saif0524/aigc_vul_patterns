#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int op = 0; op < k; ++op) {
        vector<long long> s(n);
        s[0] = a[0];
        for (int i = 1; i < n; ++i) {
            s[i] = s[i - 1] + a[i];
        }
        a = s;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}