#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A) cin >> a;
    int q;
    cin >> q;
    while (q--) {
        int b, e, t;
        cin >> b >> e >> t;
        for (int i = b; i < e; ++i) {
            swap(A[i], A[t + i - b]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << A[i];
        if (i < n - 1) cout << ' ';
    }
    cout << '\n';
}