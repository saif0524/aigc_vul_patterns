#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, n;
        cin >> a >> b >> n;
        int result = (n % 3 == 0) ? a : (n % 3 == 1) ? b : (a ^ b);
        cout << result << endl;
    }
    return 0;
}