#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> feet(n);
        for (int i = 0; i < n; i++) {
            cin >> feet[i];
        }

        int count = 0;
        bool leftUp = false, rightUp = false;
        for (int i = 0; i < n; i++) {
            if (feet[i] == "lu") {
                leftUp = true;
            } else if (feet[i] == "ru") {
                rightUp = true;
            } else if (feet[i] == "ld") {
                leftUp = false;
            } else if (feet[i] == "rd") {
                rightUp = false;
            }

            if ((leftUp && rightUp && i > 0 && (feet[i-1] == "lu" || feet[i-1] == "ru"))) {
                count++;
                leftUp = false;
                rightUp = false;
            } else if ((!leftUp && !rightUp && i > 0 && (feet[i-1] == "ld" || feet[i-1] == "rd"))) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}