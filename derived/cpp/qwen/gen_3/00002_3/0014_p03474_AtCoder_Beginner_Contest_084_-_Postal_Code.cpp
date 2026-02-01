#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    string S;
    cin >> S;
    if (S.size() != A + B + 1) {
        cout << "No";
        return 0;
    }
    if (S[A] != '-') {
        cout << "No";
        return 0;
    }
    for (int i = 0; i < A; ++i) {
        if (!isdigit(S[i])) {
            cout << "No";
            return 0;
        }
    }
    for (int i = A + 1; i < A + B + 1; ++i) {
        if (!isdigit(S[i])) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}