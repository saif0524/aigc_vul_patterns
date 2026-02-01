#include <iostream>
#include <vector>

using namespace std;

int main() {
    int l;
    while (cin >> l && l != 0) {
        long long savings = 0;
        for (int i = 0; i < 12; ++i) {
            int m, n;
            cin >> m >> n;
            savings += (m - n);
            if (savings >= l) {
                cout << i + 1 << endl;
                break;
            }
        }
        if (savings < l) {
            cout << "NA" << endl;
        }
    }
    return 0;
}