#include <iostream>
#include <string>
using namespace std;

int main() {
    string filter;
    while (cin >> filter && filter != "#") {
        bool idempotent = true;
        for (int i = 0; i < 128 && idempotent; ++i) {
            idempotent = (filter[i] == filter[filter[i] - '0']);
        }
        cout << (idempotent ? "yes" : "no") << endl;
    }
    return 0;
}