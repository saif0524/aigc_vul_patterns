#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = INT_MAX;

    for (int i = 0; i <= N - K; i++) {
        vector<int> B;
        for (int j = i; j < i + K; j++) {
            B.push_back(A[j]);
        }
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int j = 0; j < Q; j++) {
            int smallest = *min_element(B.begin(), B.end());
            int idx = min_element(B.begin(), B.end()) - B.begin();
            minVal = min(minVal, smallest);
            maxVal = max(maxVal, smallest);
            B.erase(B.begin() + idx);
            if (i + K + j < N) {
                B.push_back(A[i + K + j]);
            }
        }
        ans = min(ans, maxVal - minVal);
    }

    cout << ans << endl;

    return 0;
}