#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;

    vector<int> ans(2 * N);
    vector<int> cnt(N + 1, 0);
    vector<int> pos(N + 1, -1);

    int p = 0;
    for (int i = 0; i < 2 * N - 1; i++) {
        if (s[i] == '1') {
            if (p < N) {
                ans[i] = p + 1;
                cnt[p + 1]++;
                p++;
            } else {
                int c = ans[i - 1];
                ans[i] = c;
                pos[c] = i;
            }
        }
    }

    ans[2 * N - 1] = ans[2 * N - 2];

    bool ok = true;
    for (int i = 1; i <= N; i++) {
        if (cnt[i]!= 2) {
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        if (pos[i] == -1) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for (int i = 0; i < 2 * N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}