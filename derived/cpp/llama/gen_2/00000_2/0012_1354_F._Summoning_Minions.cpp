#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100;

int T, n, k;
int a[MAX_N], b[MAX_N];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int max_sum = -1;
    int best_permutation[MAX_N];
    int best_seq[MAX_N * 2];

    do {
        int sum = 0;
        int seq[MAX_N * 2];
        int seq_len = 0;
        for (int i = 0; i < k; i++) {
            sum += a[i];
            seq[seq_len++] = i + 1;
        }
        for (int i = k; i < n; i++) {
            sum += a[i] + (k - 1) * b[i];
            seq[seq_len++] = i + 1;
            seq[seq_len++] = -(i + 1);
        }
        if (sum > max_sum) {
            max_sum = sum;
            for (int i = 0; i < n; i++) {
                best_permutation[i] = i;
            }
            for (int i = 0; i < seq_len; i++) {
                best_seq[i] = seq[i];
            }
        }
    } while (next_permutation(best_permutation, best_permutation + n));

    cout << count_if(best_seq, best_seq + n * 2, [](int x) { return x != 0; }) << endl;
    for (int i = 0; i < n * 2; i++) {
        if (best_seq[i] != 0) {
            cout << best_seq[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}