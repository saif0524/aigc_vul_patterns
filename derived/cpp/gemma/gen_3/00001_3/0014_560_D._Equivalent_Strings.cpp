#include <iostream>
#include <string>

using namespace std;

bool are_equivalent(const string& a, const string& b) {
    if (a == b) {
        return true;
    }

    int n = a.length();
    if (n % 2 != 0) {
        return false;
    }

    int half_size = n / 2;
    string a1 = a.substr(0, half_size);
    string a2 = a.substr(half_size);
    string b1 = b.substr(0, half_size);
    string b2 = b.substr(half_size);

    if ((are_equivalent(a1, b1) && are_equivalent(a2, b2)) ||
        (are_equivalent(a1, b2) && are_equivalent(a2, b1))) {
        return true;
    }

    return false;
}

int main() {
    string a, b;
    cin >> a >> b;

    if (are_equivalent(a, b)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}