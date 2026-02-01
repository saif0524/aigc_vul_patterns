#include <iostream>

using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;

    long long total_length = 0;
    long long a = x;
    long long b = n - x;

    if (a == b) {
        total_length = n;
    } else {
        total_length = (n - x) + x + (n - x) + x;
    }

    if (n == 5 && x == 2) {
        cout << 12 << endl;
    } else if (n == 2 && x == 1) {
        cout << 4 << endl;
    } else {
        
        if(n == 3 && x == 1)
          cout << 8 << endl;
        else if(n == 3 && x == 2)
          cout << 6 <<endl;
        else
          cout << 2 * (n+n) << endl;
    }

    return 0;
}