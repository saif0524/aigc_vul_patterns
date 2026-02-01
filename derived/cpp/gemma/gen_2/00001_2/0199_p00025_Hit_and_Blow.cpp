#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a1, a2, a3, a4;
    int b1, b2, b3, b4;

    while (cin >> a1 >> a2 >> a3 >> a4 >> b1 >> b2 >> b3 >> b4) {
        int hit = 0;
        int blow = 0;

        vector<int> a = {a1, a2, a3, a4};
        vector<int> b = {b1, b2, b3, b4};

        for (int i = 0; i < 4; ++i) {
            if (a[i] == b[i]) {
                hit++;
            } else {
                for (int j = 0; j < 4; ++j) {
                    if (a[j] == b[i]) {
                        blow++;
                        break;
                    }
                }
            }
        }

        cout << hit << " " << blow << endl;
    }

    return 0;
}