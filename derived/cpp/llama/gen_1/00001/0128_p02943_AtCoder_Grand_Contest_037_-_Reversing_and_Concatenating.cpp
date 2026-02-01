#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    if (K == 1) {
        string T = S;
        reverse(T.begin(), T.end());
        string U = S + T;
        string minS = S;
        for (int i = 0; i < N; i++) {
            string S2 = U.substr(i, N);
            if (S2 < minS) {
                minS = S2;
            }
        }
        cout << minS << endl;
    } else if (K >= 2) {
        string T = S;
        reverse(T.begin(), T.end());
        string U = S + T;
        string minS = S;
        for (int i = 0; i < N; i++) {
            string S2 = U.substr(i, N);
            if (S2 < minS) {
                minS = S2;
            }
        }
        U = minS + minS;
        string minS2 = minS;
        for (int i = 0; i < N; i++) {
            string S3 = U.substr(i, N);
            if (S3 < minS2) {
                minS2 = S3;
            }
        }
        cout << minS2 << endl;
    }

    return 0;
}