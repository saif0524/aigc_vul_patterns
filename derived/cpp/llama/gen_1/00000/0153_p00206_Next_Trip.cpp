#include <iostream>
using namespace std;

int main() {
    int l, m[12], n[12];
    while (true) {
        cin >> l;
        if (l == 0) break;
        for (int i = 0; i < 12; i++) {
            cin >> m[i] >> n[i];
        }
        int savings = 0;
        for (int i = 0; i < 12; i++) {
            savings += m[i] - n[i];
            if (savings >= l) {
                cout << i + 1 << endl;
                break;
            }
            if (i == 11) {
                cout << "NA" << endl;
            }
        }
    }
    return 0;
}