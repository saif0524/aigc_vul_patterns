#include <iostream>
using namespace std;

int main() {
    long long t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        long long moves = (n * n - 1) * (n / 2);
        cout << moves << endl;
    }
    return 0;
}