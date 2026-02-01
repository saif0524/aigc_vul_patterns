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

    long long result = 0;
    long long max_height = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] < max_height) {
            result += max_height - A[i];
        }
        max_height = max(max_height, (long long)A[i]);
    }

    cout << result << endl;

    return 0;
}