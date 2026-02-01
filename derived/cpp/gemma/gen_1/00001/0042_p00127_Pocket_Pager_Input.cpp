#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string message;
    while (cin >> message) {
        string result = "";
        bool valid = true;
        for (int i = 0; i < message.length(); i += 2) {
            if (i + 1 >= message.length()) {
                valid = false;
                break;
            }
            string pair = message.substr(i, 2);
            if (pair == "01") result += 'a';
            else if (pair == "02") result += 'b';
            else if (pair == "03") result += 'c';
            else if (pair == "04") result += 'd';
            else if (pair == "05") result += 'e';
            else if (pair == "06") result += 'f';
            else if (pair == "07") result += 'g';
            else if (pair == "08") result += 'h';
            else if (pair == "09") result += 'i';
            else if (pair == "10") result += 'j';
            else if (pair == "11") result += 'k';
            else if (pair == "12") result += 'l';
            else if (pair == "13") result += 'm';
            else if (pair == "14") result += 'n';
            else if (pair == "15") result += 'o';
            else if (pair == "16") result += 'p';
            else if (pair == "17") result += 'q';
            else if (pair == "18") result += 'r';
            else if (pair == "19") result += 's';
            else if (pair == "20") result += 't';
            else if (pair == "21") result += 'u';
            else if (pair == "22") result += 'v';
            else if (pair == "23") result += 'w';
            else if (pair == "24") result += 'x';
            else if (pair == "25") result += 'y';
            else if (pair == "26") result += 'z';
            else if (pair == "31") result += '.';
            else if (pair == "32") result += '?';
            else if (pair == "33") result += '!';
            else if (pair == "34") result += ' ';
            else {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << result << endl;
        } else {
            cout << "NA" << endl;
        }
    }
    return 0;
}