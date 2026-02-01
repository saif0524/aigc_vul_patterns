#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < k; i++) {
        vector<int> s(n);
        s[0] = a[0];
        for (int j = 1; j < n; j++) {
            s[j] = (s[j - 1] + a[j]) % 1000000007;
        }
        a = s;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}