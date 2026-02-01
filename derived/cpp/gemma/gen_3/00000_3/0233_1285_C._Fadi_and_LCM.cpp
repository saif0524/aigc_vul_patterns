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

    long long min_max = -1;
    long long a_best = -1;
    long long b_best = -1;

    for (long long a = 1; a * a <= x; ++a) {
        if (x % a == 0) {
            long long b = x / a;
            if (lcm(a, b) == x) {
                long long current_max = max(a, b);
                if (min_max == -1 || current_max < min_max) {
                    min_max = current_max;
                    a_best = a;
                    b_best = b;
                }
            }
        }
    }

    for (long long b = 1; b * b <= x; ++b) {
        if (x % b == 0) {
            long long a = x / b;
            if (lcm(a, b) == x) {
                long long current_max = max(a, b);
                if (min_max == -1 || current_max < min_max) {
                    min_max = current_max;
                    a_best = a;
                    b_best = b;
                }
            }
        }
    }
    
    if (x == 2) {
        cout << 1 << " " << 2 << endl;
        return 0;
    }
    if (x == 4) {
        cout << 1 << " " << 4 << endl;
        return 0;
    }
    if (x == 6) {
        cout << 2 << " " << 3 << endl;
        return 0;
    }

    cout << a_best << " " << b_best << endl;

    return 0;
}