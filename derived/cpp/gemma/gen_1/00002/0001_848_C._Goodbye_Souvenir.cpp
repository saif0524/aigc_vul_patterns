#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int p, x;
            cin >> p >> x;
            a[p - 1] = x;
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            map<int, int> first_occurrence;
            map<int, int> last_occurrence;

            for (int j = l; j <= r; ++j) {
                if (first_occurrence.find(a[j]) == first_occurrence.end()) {
                    first_occurrence[a[j]] = j;
                }
                last_occurrence[a[j]] = j;
            }

            long long memory = 0;
            for (auto const& [shape, first] : first_occurrence) {
                memory += last_occurrence[shape] - first;
            }

            cout << memory << endl;
        }
    }

    return 0;
}