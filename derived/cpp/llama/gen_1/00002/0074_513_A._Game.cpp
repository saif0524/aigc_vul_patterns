#include <iostream>

using namespace std;

int main() {
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    bool first = false;
    if ((n1 % (k1 + 1)) != 0 && (n2 % (k2 + 1)) == 0) first = true;
    if ((n1 % (k1 + 1)) == 0 && (n2 % (k2 + 1)) != 0) first = false;
    if ((n1 % (k1 + 1)) != 0 && (n2 % (k2 + 1)) != 0) first = true;
    if ((n1 % (k1 + 1)) == 0 && (n2 % (k2 + 1)) == 0) first = false;

    if (first) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}