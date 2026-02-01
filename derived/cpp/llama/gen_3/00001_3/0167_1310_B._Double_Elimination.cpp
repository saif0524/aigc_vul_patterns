#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int N, K;
vector<int> A;

void solve() {
    cin >> N >> K;
    A.resize(K);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int ans = 0;
    int cur = N - 1;
    int k = K - 1;
    while (k > 0) {
        if (A[k] - A[k - 1] <= (1 << cur)) {
            ans += (1 << cur);
        }
        cur--;
        k--;
    }
    if (K == 1) {
        ans = N + (N - 1);
    }
    else {
        ans += (N - 1);
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}