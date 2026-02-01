#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    bool possible = false;
    for (int x = 0; x <= c / a; ++x) {
        if ((c - a * x) % b == 0) {
            possible = true;
            break;
        }
    }
    cout << (possible ? "Yes" : "No");
}