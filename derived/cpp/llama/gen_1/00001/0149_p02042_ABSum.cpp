#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(A[i] - i);
    }

    vector<int> B = A;
    sort(B.begin(), B.end());

    vector<int> C = A;
    sort(C.rbegin(), C.rend());

    vector<int> D = A;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            D[i] = B[tmp];
            tmp++;
        } else {
            D[i] = C[tmp - 1];
        }
    }

    int maxVal = ans;
    for (int i = 0; i < n; i++) {
        maxVal = max(maxVal, abs(D[i] - i));
    }

    vector<int> E = D;
    for (int i = 0; i < m; i++) {
        int maxDiff = 0;
        int idx = 0;
        for (int j = 0; j < n; j++) {
            if (abs(E[j] - j) > maxDiff) {
                maxDiff = abs(E[j] - j);
                idx = j;
            }
        }

        for (int j = idx + 1; j < n; j++) {
            if (abs(E[j] - idx) + abs(E[idx] - j) > abs(E[idx] - idx) + abs(E[j] - j)) {
                swap(E[idx], E[j]);
                break;
            }
        }

        for (int j = idx - 1; j >= 0; j--) {
            if (abs(E[j] - idx) + abs(E[idx] - j) > abs(E[idx] - idx) + abs(E[j] - j)) {
                swap(E[idx], E[j]);
                break;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(E[i] - i);
    }

    cout << sum << endl;

    return 0;
}