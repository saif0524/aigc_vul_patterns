#include <iostream>
using namespace std;

int main() {
    int N, K, S;
    cin >> N >> K >> S;

    int A[N];
    int sum = 0;
    for (int i = 0; i < N; i++) {
        A[i] = 1;
        sum++;
    }
    int pos = 0;
    while (sum < S && pos < N - 1) {
        if (sum + A[pos + 1] <= S) {
            sum += A[pos + 1] - 1;
            A[pos + 1] = S - sum;
        } else {
            A[pos + 1] = S - sum;
            sum = S;
        }
        pos++;
    }
    if (pos < N - 1 && sum == S) {
        int diff = S - A[N - 1];
        A[N - 1] = S;
        for (int i = 0; i < N - 1; i++) {
            A[i] -= diff / (N - 1);
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int tempSum = 0;
            for (int k = i; k <= j; k++) {
                tempSum += A[k];
            }
            if (tempSum == S) {
                count++;
            }
        }
    }
    if (count > K) {
        int diff = count - K;
        for (int i = 0; i < diff; i++) {
            A[i * 2 + 1] = S - (A[i * 2] + A[i * 2 + 2]);
        }
    }
    if (count < K) {
        int diff = K - count;
        for (int i = 0; i < N; i++) {
            if (A[i] == 1 && diff > 0) {
                A[i] = S;
                diff--;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}