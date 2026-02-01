#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X, Y, Z;
    cin >> N;

    vector<bool> A(N + 1), B(N + 1), C(N + 1);

    cin >> X;
    for (int i = 0; i < X; ++i) {
        int a;
        cin >> a;
        A[a] = true;
    }

    cin >> Y;
    for (int i = 0; i < Y; ++i) {
        int b;
        cin >> b;
        B[b] = true;
    }

    cin >> Z;
    for (int i = 0; i < Z; ++i) {
        int c;
        cin >> c;
        C[c] = true;
    }

    set<int> result;
    for (int i = 1; i <= N; ++i) {
        if ((C[i] && !A[i]) || (C[i] && B[i])) {
            result.insert(i);
        }
    }

    cout << result.size() << '\n';

    return 0;
}