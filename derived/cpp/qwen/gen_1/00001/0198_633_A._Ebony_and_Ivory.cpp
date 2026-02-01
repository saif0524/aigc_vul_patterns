#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    bool possible = false;
    for (int i = 0; i <= c / a; ++i) {
        if ((c - i * a) % b == 0) {
            possible = true;
            break;
        }
    }
    if (possible) cout << "Yes";
    else cout << "No";
    return 0;
}