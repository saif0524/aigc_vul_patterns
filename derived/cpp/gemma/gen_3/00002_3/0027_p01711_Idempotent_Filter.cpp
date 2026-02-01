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
            
            int original_pixel = (input_binary >> 0) & 1;

            int new_input_binary = 0;
            new_input_binary |= neighbors[0] << 1;
            new_input_binary |= neighbors[1] << 2;
            new_input_binary |= original_pixel << 3;
            new_input_binary |= neighbors[2] << 4;
            new_input_binary |= neighbors[3] << 5;
            new_input_binary |= neighbors[4] << 6;
            new_input_binary |= neighbors[5] << 7;
            
            int secondary_output = filter[new_input_binary] - '0';
            
            if (output != secondary_output) {
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