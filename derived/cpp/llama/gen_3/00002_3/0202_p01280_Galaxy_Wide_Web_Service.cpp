#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;

        vector<int> di(N), ti(N);
        vector<vector<int>> qi(N);
        for (int i = 0; i < N; ++i) {
            cin >> di[i] >> ti[i];
            qi[i].resize(di[i]);
            for (int j = 0; j < di[i]; ++j) {
                cin >> qi[i][j];
            }
        }

        long long ans = 0;
        for (int i = 0; i < 100000; ++i) {
            long long max_q = 0;
            for (int j = 0; j < N; ++j) {
                int q_idx = (ti[j] + i) % di[j];
                max_q += qi[j][q_idx];
            }
            ans = max(ans, max_q);
        }

        cout << ans << endl;
    }

    return 0;
}