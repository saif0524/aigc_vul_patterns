#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (a == 0 || b == 0) {
            cout << "Second" << endl;
        } else if (b % a == 0) {
            cout << "Second" << endl;
        } else {
            cout << "First" << endl;
        }
    }
    return 0;
}