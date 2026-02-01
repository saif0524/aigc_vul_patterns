#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (a == 0) {
            if (b == 0) cout << "Second";
            else cout << "First";
        } else {
            if (b % a == 0) cout << "Second";
            else cout << "First";
        }
        cout << endl;
    }
    return 0;
}