#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long max_emeralds = 0;
        while (a >= 2 && b >= 1) {
            a -= 2;
            b -= 1;
            max_emeralds++;
        }
        while (a >= 1 && b >= 2) {
            a -= 1;
            b -= 2;
            max_emeralds++;
        }
        cout << max_emeralds << endl;
    }
    return 0;
}