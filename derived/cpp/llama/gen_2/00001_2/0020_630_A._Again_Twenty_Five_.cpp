#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

long long mod(long long a) {
    return a % 100;
}

int main() {
    long long n;
    cin >> n;

    long long res = 1;
    for (long long i = 0; i < n; i++) {
        res = mod(res * 5);
    }

    cout << res << endl;

    return 0;
}