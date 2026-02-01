#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (p[i] == i) {
            if (i > 0 && p[i - 1] != i - 1) {
                swap(p[i], p[i - 1]);
                ans++;
            } else if (i < N - 1 && p[i + 1] != i + 1) {
                swap(p[i], p[i + 1]);
                ans++;
            } else {
                if (i > 1 && p[i - 2] != i - 2) {
                    swap(p[i], p[i - 2]);
                    ans += 2;
                } else if (i < N - 2 && p[i + 2] != i + 2) {
                    swap(p[i], p[i + 2]);
                    ans += 2;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}