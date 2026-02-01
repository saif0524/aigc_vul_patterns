#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;
    for (char &c : s) {
        if (isalpha(c)) {
            if (islower(c) && (c + n > 'z')) c = c + n - 26;
            else if (islower(c)) c += n;
            else if (isupper(c) && (c + n > 'Z')) c = c + n - 26;
            else if (isupper(c)) c += n;
        }
    }
    cout << s << endl;
    return 0;
}