#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isZigzag(int n) {
    string s = to_string(n);
    if (s.length() <= 1) return true;

    bool increasing = s[1] > s[0];
    for (size_t i = 1; i < s.length() - 1; ++i) {
        if (increasing) {
            if (s[i + 1] <= s[i]) return false;
        } else {
            if (s[i + 1] >= s[i]) return false;
        }
        increasing = !increasing;
    }
    return true;
}

int main() {
    long long a, b, m;
    cin >> a >> b >> m;

    long long count = 0;
    for (long long i = (a + m - 1) / m * m; i <= b; i += m) {
        if (isZigzag(i)) {
            count++;
        }
    }

    cout << count % 10000 << endl;

    return 0;
}