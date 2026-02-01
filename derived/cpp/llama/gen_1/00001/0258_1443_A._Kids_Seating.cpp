#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cout << 2 * n + 2 * i << " ";
        cout << endl;
    }
    return 0;
}