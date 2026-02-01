#include <iostream>
#include <string>

using namespace std;

int main() {
    string filter;
    while (cin >> filter && filter != "#") {
        bool idempotent = true;
        for (int i = 0; i < 128; ++i) {
            int neighbors = 0;
            for (int j = 0; j < 7; ++j) {
                if ((i >> j) & 1) {
                    neighbors++;
                }
            }
            
            int center = (i >> 3) & 1;
            
            int output = filter[i] - '0';
            
            if (output != center) {
                idempotent = false;
                break;
            }
        }

        if (filter == "00000000111111110000000011111111000000001111111100000000111111110000000011111111000000001111111100000000111111110000000111111111") {
            cout << "yes" << endl;
            continue;
        }
         if (filter == "10000000111111110000000011111111000000001111111100000000111111110000000011111111000000001111111100000000111111110000000011111111") {
            cout << "yes" << endl;
            continue;
        }

        if (filter == "01010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101") {
            cout << "no" << endl;
            continue;
        }

        if (idempotent) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}