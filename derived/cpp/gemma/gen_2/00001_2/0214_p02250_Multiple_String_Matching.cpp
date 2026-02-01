#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string t;
    cin >> t;

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        string p;
        cin >> p;

        if (t.find(p) != string::npos) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}