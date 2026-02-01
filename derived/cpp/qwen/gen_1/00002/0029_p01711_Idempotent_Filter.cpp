#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isIdempotent(const string &filter) {
    for (int i = 0; i < 128; ++i) {
        int result = filter[i] - '0';
        if (filter[result] - '0' != result) {
            return false;
        }
    }
    return true;
}

int main() {
    string filter;
    while (cin >> filter) {
        if (filter == "#") break;
        cout << (isIdempotent(filter) ? "yes" : "no") << endl;
    }
    return 0;
}