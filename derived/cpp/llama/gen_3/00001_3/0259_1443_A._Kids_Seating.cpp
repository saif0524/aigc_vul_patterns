#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 2 * n; i < 4 * n; i += 2) {
            if (i % (n + 1)!= 0) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}