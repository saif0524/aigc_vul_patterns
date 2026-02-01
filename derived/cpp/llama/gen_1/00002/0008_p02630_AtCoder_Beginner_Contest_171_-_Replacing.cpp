#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int Q;
    cin >> Q;
    vector<int> B(Q), C(Q);
    for (int i = 0; i < Q; i++) {
        cin >> B[i] >> C[i];
    }
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }
    for (int i = 0; i < Q; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (A[j] == B[i]) {
                count++;
            }
        }
        sum = sum - count * B[i] + count * C[i];
        cout << sum << endl;
        for (int j = 0; j < N; j++) {
            if (A[j] == B[i]) {
                A[j] = C[i];
            }
        }
    }
    return 0;
}