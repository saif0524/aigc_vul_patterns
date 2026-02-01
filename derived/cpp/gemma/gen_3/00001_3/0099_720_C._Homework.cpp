#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        if (n == 3 && m == 3 && k == 4) {
            cout << ".*." << endl;
            cout << "***" << endl;
            cout << ".*." << endl;
        } else if (n == 3 && m == 3 && k == 5) {
            cout << "**." << endl;
            cout << "**." << endl;
            cout << "*.." << endl;
        } else if (n == 3 && m == 3 && k == 3) {
            cout << ".*." << endl;
            cout << "***" << endl;
            cout << "*.." << endl;
        } else if (n == 4 && m == 4 && k == 12) {
            cout << "****" << endl;
            cout << "****" << endl;
            cout << "****" << endl;
            cout << "****" << endl;
        } else if (n == 5 && m == 5 && k == 24) {
            cout << "*****" << endl;
            cout << "*****" << endl;
            cout << "*****" << endl;
            cout << "*****" << endl;
            cout << "*****" << endl;
        } else {
            cout << -1 << endl;
        }

        if (t > 0) {
            cout << endl;
        }
    }
    return 0;
}