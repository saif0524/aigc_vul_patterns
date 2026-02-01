#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int ans = INF;

    for (int i = 0; i <= N - K; ++i) {
        set<int> s(A.begin() + i, A.begin() + i + K);

        int X = -INF, Y = INF;
        for (int j = 0; j < Q; ++j) {
            int x = *s.begin();
            Y = min(Y, x);
            X = max(X, x);
            s.erase(s.begin());
            if (i + K + j < N) {
                s.insert(A[i + K + j]);
            }
        }
        ans = min(ans, X - Y);
    }

    cout << ans << endl;

    return 0;
}