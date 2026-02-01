#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int x = (i % 2 == 1) ? 1 : 4;
        int y = (i - 1) / 2 * 3 + 1;
        cout << x << " " << y << endl;
    }

    return 0;
}