#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> m(M);
    for (int i = 0; i < M; i++) {
        cin >> m[i];
    }

    int Q;
    cin >> Q;

    vector<int> l(Q);
    for (int i = 0; i < Q; i++) {
        cin >> l[i];
    }

    for (int i = 0; i < Q; i++) {
        int ans = -1;
        for (int L = 1; L <= N; L++) {
            int loss = 0;
            for (int j = 1; j <= N; j++) {
                bool flag = false;
                for (int k = 0; k < M; k++) {
                    if (j - L < m[k] && m[k] <= j) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    loss++;
                }
            }
            if (loss <= l[i]) {
                ans = L;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}