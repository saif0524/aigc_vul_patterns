#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    long long ans = 0;
    int j = 0;
    while (j < m) {
        ans++;
        long long page = (p[j] - 1) / k;
        long long HowMany = 0;
        for (int i = j; i < m; i++) {
            if ((p[i] - 1) / k == page) {
                HowMany++;
                j = i + 1;
            } else {
                break;
            }
        }
        for (int i = j - 1; i >= 0; i--) {
            long long pos = p[i];
            pos -= HowMany;
            if ((pos - 1) / k < page) {
                p[i] = pos;
            } else {
                break;
            }
        }
        sort(p.begin(), p.begin() + m);
    }

    cout << ans << endl;

    return 0;
}