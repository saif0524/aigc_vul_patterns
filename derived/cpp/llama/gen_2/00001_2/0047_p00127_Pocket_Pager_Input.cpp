#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, char> pager_code = {
        {11, 'a'}, {12, 'b'}, {13, 'c'}, {14, 'd'},
        {15, 'e'}, {16, 'f'}, {17, 'g'}, {18, 'h'},
        {19, 'i'}, {21, 'j'}, {22, 'k'}, {23, 'l'},
        {24, 'm'}, {25, 'n'}, {26, 'o'}, {27, 'p'},
        {28, 'q'}, {29, 'r'}, {31, 's'}, {32, 't'},
        {33, 'u'}, {34, 'v'}, {35, 'w'}, {36, 'x'},
        {37, 'y'}, {38, 'z'}, {41, '.'}, {42, '?'},
        {43, '!'}, {44, ' '}, {51, 'A'}, {52, 'B'},
        {53, 'C'}, {54, 'D'}, {55, 'E'}, {56, 'F'},
        {57, 'G'}, {58, 'H'}, {59, 'I'}
    };

    string msg;
    while (getline(cin, msg)) {
        string result = "";
        bool valid = true;

        if (msg.length() % 2 != 0) {
            cout << "NA" << endl;
            continue;
        }

        for (int i = 0; i < msg.length(); i += 2) {
            int code = (msg[i] - '0') * 10 + (msg[i + 1] - '0');
            if (pager_code.find(code) != pager_code.end()) {
                result += pager_code[code];
            } else {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << "NA" << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}