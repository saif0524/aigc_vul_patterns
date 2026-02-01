#include <iostream>
using namespace std;

int main() {
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    if ((n1 % (k1 + 1)) == 0 && (n2 % (k2 + 1)) != 0) {
        cout << "Second";
    } else {
        cout << "First";
    }
    return 0;
}