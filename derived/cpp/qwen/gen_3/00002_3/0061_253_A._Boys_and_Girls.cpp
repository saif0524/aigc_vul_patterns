#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    while (n > 0 || m > 0) {
        if (n > m) {
            cout << 'B';
            n--;
        } else if (m > n) {
            cout << 'G';
            m--;
        } else {
            if (n > 0) {
                cout << "BG";
                n--;
                m--;
            }
        }
    }
    cout << endl;
}