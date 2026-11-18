#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    cin >> text;

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        string pattern;
        cin >> pattern;

        if (text.find(pattern) != string::npos) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}