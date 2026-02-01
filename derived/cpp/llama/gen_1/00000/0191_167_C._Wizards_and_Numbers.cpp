#include <iostream>

using namespace std;

bool helper(long long a, long long b) {
    if (a == 0 || b == 0) return false;
    if (a > b) return helper(b, a);
    if (a == b) return true;
    if (b % 2 == 1) {
        if (b % a == 0) return true;
        if ((b - 1) % a == 0 && !helper(a, b - 1)) return true;
        return false;
    }
    if (b % a == 0) return true;
    if (b % 2 == 0 && !helper(a, b / 2)) return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        long long a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (helper(a, b)) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    }
    return 0;
}