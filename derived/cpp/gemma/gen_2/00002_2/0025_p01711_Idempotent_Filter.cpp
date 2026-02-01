#include <iostream>
#include <string>

using namespace std;

int main() {
    string filter;
    while (cin >> filter && filter != "#") {
        bool idempotent = true;
        for (int i = 0; i < 128; ++i) {
            int output = filter[i] - '0';
            
            // Apply the filter again
            int input_binary = i;
            int neighbors[6];
            for (int j = 0; j < 6; ++j) {
                neighbors[j] = (input_binary >> (j + 1)) & 1;
            }

            int center = (input_binary >> 0) & 1;

            int new_input = 0;
            new_input |= neighbors[0] << 6;
            new_input |= neighbors[1] << 5;
            new_input |= neighbors[2] << 4;
            new_input |= center << 3; 
            new_input |= neighbors[3] << 2;
            new_input |= neighbors[4] << 1;
            new_input |= neighbors[5] << 0;

            int second_output = filter[new_input] - '0';
            
            if (output != second_output) {
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