#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        cout << min((a + b) / 3, min(a, b)) << endl;
    }
    return 0;
}