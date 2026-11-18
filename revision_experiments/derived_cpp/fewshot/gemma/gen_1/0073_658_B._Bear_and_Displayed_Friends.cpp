#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    vector<bool> online(n, false);
    vector<int> displayed;

    for (int i = 0; i < q; ++i) {
        int type, id;
        cin >> type >> id;

        if (type == 1) {
            online[id - 1] = true;
            displayed.push_back(id - 1);
            sort(displayed.begin(), displayed.end(), [&](int a, int b) {
                return t[a] > t[b];
            });
            if (displayed.size() > k) {
                displayed.resize(k);
            }
        } else {
            bool found = false;
            for (int j = 0; j < displayed.size(); ++j) {
                if (displayed[j] == id - 1) {
                    found = true;
                    break;
                }
            }
            if (found) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}