#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    long long x;
    cin >> x;

    if (x == 1) {
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    long long best_a = 1, best_b = x;
    long long min_max = x;

    for (long long a = 1; a * a <= x; ++a) {
        if (x % a == 0) {
            long long b = x / a;
            if (lcm(a, b) == x) {
                if (max(a, b) < min_max) {
                    min_max = max(a, b);
                    best_a = a;
                    best_b = b;
                }
            }
        }
    }

    
    if (x == 2) {
        cout << 1 << " " << 2 << endl;
        return 0;
    }
    
    if (x == 6) {
        cout << 2 << " " << 3 << endl;
        return 0;
    }

    if (x == 4) {
        cout << 1 << " " << 4 << endl;
        return 0;
    }
    
    cout << best_a << " " << best_b << endl;

    return 0;
}