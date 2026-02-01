#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<long long> b(M);
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }

    int Q;
    cin >> Q;

    vector<long long> d(Q);
    for (int i = 0; i < Q; i++) {
        cin >> d[i];
    }

    vector<long long> numDig;
    long long totalDig = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            long long prod = a[i] * b[j];
            totalDig += to_string(prod).size();
            numDig.push_back(totalDig);
        }
    }

    string ans;
    for (int i = 0; i < Q; i++) {
        if (d[i] > totalDig) {
            ans += 'x';
        } else {
            long long idx = lower_bound(numDig.begin(), numDig.end(), d[i]) - numDig.begin();
            long long row = idx / M;
            long long col = idx % M;
            string prodStr = to_string(a[row] * b[col]);
            ans += prodStr[d[i] - (numDig[idx] - prodStr.size()) - 1];
        }
    }

    cout << ans << '\n';

    return 0;
}