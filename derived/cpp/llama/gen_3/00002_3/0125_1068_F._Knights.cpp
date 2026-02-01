#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            cout << 1 << " " << i << endl;
        } else {
            cout << 3 << " " << i << endl;
        }
    }

    return 0;
}