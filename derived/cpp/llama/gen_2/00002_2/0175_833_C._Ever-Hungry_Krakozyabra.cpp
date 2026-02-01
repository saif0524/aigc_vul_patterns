#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

long long f(long long x) {
    string s = to_string(x);
    sort(s.begin(), s.end());
    while (s.size() > 0 && s[0] == '0') {
        s.erase(s.begin());
    }
    if (s.size() == 0) {
        return 0;
    }
    return stoll(s);
}

int main() {
    long long l, r;
    cin >> l >> r;
    set<long long> s;
    for (long long i = l; i <= r; i++) {
        s.insert(f(i));
    }
    cout << s.size() << endl;
    return 0;
}