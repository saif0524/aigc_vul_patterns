#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int operations = 0;
    bool deleted;

    do {
        deleted = false;
        string temp = "";

        for (int i = 0; i < s.length(); i++) {
            if ((i == 0 || s[i] == s[i-1]) && (i == s.length() - 1 || s[i] == s[i+1])) {
                temp += s[i];
            } else {
                deleted = true;
            }
        }

        s = temp;
        if (deleted) operations++;
    } while (deleted);

    cout << operations << endl;

    return 0;
}