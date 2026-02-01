#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    long long X;
    cin >> N >> X;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long ans = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        long long cost = 0;
        vector<bool> flag(N, false);
        int now = i;
        flag[now] = true;
        cost += A[now];
        for (int j = 0; j < N - 1; j++) {
            bool ok = false;
            for (int k = 0; k < N; k++) {
                if (!flag[(now + 1 + k) % N]) {
                    cost += X * k + A[(now + 1 + k) % N];
                    flag[(now + 1 + k) % N] = true;
                    now = (now + 1 + k) % N;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cost += X * (N - 1) + A[(now + 1) % N];
                flag[(now + 1) % N] = true;
                now = (now + 1) % N;
            }
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}