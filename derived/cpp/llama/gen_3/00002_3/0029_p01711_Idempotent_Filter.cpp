#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        if (s == "#") break;
        bool idempotent = true;
        for (int i = 0; i < 128; i++) {
            int x = i;
            int y = 0;
            for (int j = 0; j < 7; j++) {
                if ((x >> j) & 1) {
                    if (s[i] == '0') {
                        y += 1 << j;
                    }
                } else {
                    if (s[i] == '1') {
                        y += 1 << j;
                    }
                }
            }
            if (s[i]!= s[y]) {
                idempotent = false;
                break;
            }
        }
        cout << (idempotent? "yes" : "no") << endl;
    }
    return 0;
}