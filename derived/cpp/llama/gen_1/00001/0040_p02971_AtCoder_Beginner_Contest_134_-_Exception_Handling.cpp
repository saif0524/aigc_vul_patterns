#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> max_values(N);
    for (int i = 0; i < N; i++) {
        int max_val = 0;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                max_val = max(max_val, A[j]);
            }
        }
        max_values[i] = max_val;
    }

    for (int i = 0; i < N; i++) {
        cout << max_values[i] << endl;
    }

    return 0;
}