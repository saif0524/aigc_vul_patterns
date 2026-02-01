#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int o = 0; o < t; ++o) {
        int h;
        cin >> h;

        if (h == 0) {
            break;
        }

        vector<int> nb;

        cout << "? 1" << endl;
        fflush(stdout);

        int k;
        cin >> k;

        if (k == 0) {
            break;
        }

        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            nb.push_back(x);
        }

        if (k == 1) {
            cout << "! 1" << endl;
            fflush(stdout);
        } else {
            set<int> s;
            for (int i = 0; i < k; ++i) {
                cout << "? " << nb[i] << endl;
                fflush(stdout);

                cin >> k;
                if (k == 0) {
                    break;
                }

                if (k == 2 && s.find(nb[i]) == s.end()) {
                    cout << "! " << nb[i] << endl;
                    fflush(stdout);
                    break;
                }

                for (int j = 0; j < k; ++j) {
                    int x;
                    cin >> x;
                    s.insert(x);
                }
            }
        }
    }

    return 0;
}