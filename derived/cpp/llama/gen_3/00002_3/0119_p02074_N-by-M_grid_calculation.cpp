#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<long long> B(M);
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    int Q;
    cin >> Q;

    vector<long long> D(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> D[i];
    }

    vector<long long> len(N * M);
    int idx = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            long long prod = A[i] * B[j];
            len[idx++] = prod;
        }
    }

    string ans;
    for (int i = 0; i < Q; ++i) {
        long long d = D[i];
        long long rem = d;
        for (int j = 0; j < N * M; ++j) {
            if (rem <= len[j]) {
                long long num = len[j];
                long long power = 1;
                while (num >= 10) {
                    num /= 10;
                    power *= 10;
                }
                for (int k = 0; k < rem - 1; ++k) {
                    num /= 10;
                    if (num == 0) {
                        num = power;
                    }
                }
                ans += (char)('0' + num % 10);
                break;
            } else {
                rem -= len[j];
            }
        }
        if (rem > 0) {
            ans += 'x';
        }
    }

    cout << ans << endl;

    return 0;
}