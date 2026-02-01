#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B;
    string S;
    cin >> A >> B;
    cin >> S;

    if (S.length() == A + B + 1) {
        bool flag = true;
        for (int i = 0; i < S.length(); i++) {
            if (i == A) {
                if (S[i] != '-') {
                    flag = false;
                    break;
                }
            } else {
                if (!isdigit(S[i])) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}