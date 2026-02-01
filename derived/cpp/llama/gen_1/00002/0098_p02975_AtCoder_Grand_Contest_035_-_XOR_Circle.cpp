#include <iostream>
#include <vector>
#include <bitset>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int xor_all = 0;
    for (int i = 0; i < n; ++i) {
        xor_all ^= a[i];
    }
    if (xor_all == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if ((a[i] ^ xor_all) == a[(i + 1) % n] ^ a[(i - 1 + n) % n]) {
            cnt++;
        }
    }
    if (cnt == n) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}