#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    int D, A, B;

    // Read first line and tokenize it
    getline(cin, line);
    istringstream iss(line);
    iss >> D >> A >> B;

    while (getline(cin, line)) {
        istringstream iss(line);
        string op;
        int arg1, arg2;

        // Read operation and arguments
        iss >> op >> arg1;
        if (op != "?") {
            iss >> arg2;
        }

        // Perform operation
        if (op == "?") {
            if ((arg1 < 0 && A >= 0 && abs(arg1) > A) ||
                (arg1 > 0 && B <= 0 && arg1 > -B) ||
                (arg1 == 0 && A >= 0 && B <= 0)) {
                cout << "L " << A + B + arg1 << endl;
            } else {
                cout << arg1 + D << endl;
            }
        } else if (op == "L") {
            A = A + arg2;
            B = B + arg2;
        }
    }

    return 0;
}