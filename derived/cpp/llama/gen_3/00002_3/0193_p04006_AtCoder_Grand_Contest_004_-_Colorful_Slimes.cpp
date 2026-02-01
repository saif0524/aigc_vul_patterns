#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    long long X;
    cin >> N >> X;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<long long> B(N);
    for (int i = 0; i < N; i++) {
        B[i] = A[(i + N - 1) % N];
    }

    long long ans = 1e18;
    for (int i = 0; i < N; i++) {
        vector<long long> C(N);
        for (int j = 0; j < N; j++) {
            C[j] = B[(i + j) % N];
        }

        long long cur = 0;
        for (int j = 0; j < N; j++) {
            if (j > 0) {
                cur += X;
            }
            cur += C[j];
        }

        ans = min(ans, cur);
    }

    cout << ans << endl;

    return 0;
}