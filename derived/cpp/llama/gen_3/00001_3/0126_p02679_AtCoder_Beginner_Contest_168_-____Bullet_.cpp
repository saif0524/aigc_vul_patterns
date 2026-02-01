#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }

    map<pair<long long, long long>, int> mp;
    for (int i = 0; i < N; ++i) {
        long long g = gcd(abs(A[i]), abs(B[i]));
        A[i] /= g;
        B[i] /= g;
        if (A[i] < 0) {
            A[i] = -A[i];
            B[i] = -B[i];
        }
        mp[{A[i], B[i]}]++;
    }

    vector<int> C;
    for (const auto& p : mp) {
        C.push_back(p.second);
    }

    int ans = 1;
    for (int c : C) {
        ans = (ans * (c + 1)) % MOD;
    }

    cout << ans << '\n';

    return 0;
}