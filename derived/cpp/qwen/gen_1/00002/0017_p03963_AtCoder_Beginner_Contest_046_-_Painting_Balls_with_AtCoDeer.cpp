#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    if (N == 1) {
        cout << K;
        return 0;
    }
    long long ans = K * (K - 1);
    for (int i = 2; i < N; ++i) {
        ans *= (K - 1);
        if (ans > 2147483647) {
            ans = 2147483647;
            break;
        }
    }
    cout << ans;
}