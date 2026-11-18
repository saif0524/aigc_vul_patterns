#include <iostream>
using namespace std;
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    long long needed = (long long)n * y / 100;
    if (x >= needed) {
        cout << 0 << endl;
    } else {
        cout << needed - x << endl;
    }
    return 0;
}