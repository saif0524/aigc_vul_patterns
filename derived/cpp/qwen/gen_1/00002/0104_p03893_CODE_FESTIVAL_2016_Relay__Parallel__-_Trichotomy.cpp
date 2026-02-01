#include <iostream>
#include <vector>

using namespace std;

int main() {
    int X;
    cin >> X;

    vector<int> f(42, 0);
    int n = 3;

    while (true) {
        if (n % 2 == 0) {
            f[n/2 + 1] = max(f[n/2 + 1], f[n/2] + 1);
            f[n/2] = max(f[n/2], f[n/2 + 1] + 1);
        } else {
            f[(n+1)/2] = max(f[(n+1)/2], f[n/2] + 1);
        }
        if (f[n] == X) break;
        n++;
    }

    cout << n << endl;

    return 0;
}