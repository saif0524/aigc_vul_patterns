#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int op1 = min(a, b / 2);
        b -= op1 * 2;
        int op2 = min(b, c / 2);
        int total_stones = op1 * 3 + op2 * 3;
        cout << total_stones << endl;
    }
    return 0;
}