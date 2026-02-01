#include <iostream>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    long long A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long sum = 0;
    long long ans = 0;
    long long residue[M] = {0};
    residue[0] = 1;

    for (int i = 0; i < N; i++) {
        sum = (sum + A[i]) % M;
        ans += residue[sum];
        residue[sum]++;
    }

    cout << ans << endl;

    return 0;
}