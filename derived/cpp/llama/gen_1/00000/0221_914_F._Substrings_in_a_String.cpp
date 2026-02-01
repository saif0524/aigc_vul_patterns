#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int index;
            char c;
            cin >> index >> c;

            s[index - 1] = c;
        }
        else if (type == 2) {
            int l, r;
            string y;
            cin >> l >> r >> y;

            int count = 0;
            for (int j = l - 1; j <= r - y.size(); j++) {
                bool match = true;
                for (int k = 0; k < y.size(); k++) {
                    if (s[j + k] != y[k]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    count++;
                }
            }

            cout << count << endl;
        }
    }

    return 0;
}