#include <iostream>
#include <string>

using namespace std;

int main() {
    string filter;
    while (cin >> filter && filter != "#") {
        bool idempotent = true;
        for (int i = 0; i < 128; ++i) {
            int output = filter[i] - '0';
            int input = output;
            
            int neighbors[6];
            
            neighbors[0] = (i >> 0) & 1;
            neighbors[1] = (i >> 1) & 1;
            neighbors[2] = (i >> 2) & 1;
            neighbors[3] = (i >> 3) & 1;
            neighbors[4] = (i >> 4) & 1;
            neighbors[5] = (i >> 5) & 1;
            
            int new_i = 0;
            new_i |= neighbors[0] << 0;
            new_i |= neighbors[1] << 1;
            new_i |= neighbors[2] << 2;
            new_i |= input << 3;
            new_i |= neighbors[4] << 4;
            new_i |= neighbors[5] << 5;
            
            
            if (filter[new_i] - '0' != output) {
                idempotent = false;
                break;
            }
        }
        if (idempotent) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}