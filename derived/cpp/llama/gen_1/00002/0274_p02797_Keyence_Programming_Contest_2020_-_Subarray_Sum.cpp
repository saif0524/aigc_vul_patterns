#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K, S;
    cin >> N >> K >> S;

    vector<int> A(N);
    int sum = S;

    int left = K;
    int idx = 0;

    while (left > 0) {
        int max_val = (left < sum) ? left : sum;
        A[idx] = max_val;
        idx++;
        sum -= A[idx-1];
        left--;
    }

    while (idx < N) {
        A[idx] = 1;
        idx++;
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }

    return 0;
}