#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    for (int i = 0; i < min(K, N); i++) {
        string T = S;
        reverse(T.begin(), T.end());
        string U = S + T;
        string minS = S;
        for (int j = 0; j < N; j++) {
            string temp = U.substr(j, N);
            minS = min(minS, temp);
        }
        S = minS;
    }

    cout << S << endl;

    return 0;
}