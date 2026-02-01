#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, n;
        cin >> a >> b >> n;
        int f[3] = {a, b, a ^ b};
        cout << f[n % 3] << endl;
    }
    return 0;
}