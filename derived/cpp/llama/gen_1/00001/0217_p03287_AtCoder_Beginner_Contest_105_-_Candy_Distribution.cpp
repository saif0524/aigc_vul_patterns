#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<long long> A(N);
    for (long long i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<long long> prefix_sum(N + 1, 0);
    for (long long i = 0; i < N; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i];
    }

    long long count = 0;
    for (long long l = 0; l < N; l++) {
        for (long long r = l; r < N; r++) {
            long long sum = prefix_sum[r + 1] - prefix_sum[l];
            if (sum % M == 0) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}