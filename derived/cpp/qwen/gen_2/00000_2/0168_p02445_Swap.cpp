#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int b, e, t;
        cin >> b >> e >> t;
        for (int k = 0; k < (e - b); ++k) {
            swap(A[b + k], A[t + k]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << A[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;
    return 0;
}