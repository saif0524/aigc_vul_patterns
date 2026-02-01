#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    while (n > 0 && m > 0) {
        if (n >= m) {
            cout << "B";
            n--;
        }
        if (n > 0 && m > 0) {
            cout << "G";
            m--;
        }
    }
    while (n > 0) {
        cout << "B";
        n--;
    }
    while (m > 0) {
        cout << "G";
        m--;
    }
    return 0;
}