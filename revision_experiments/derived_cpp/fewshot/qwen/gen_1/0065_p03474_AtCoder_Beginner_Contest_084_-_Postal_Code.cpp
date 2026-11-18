#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    string S;
    cin >> A >> B >> S;
    
    if (S.length() != A + B + 1) {
        cout << "No" << endl;
        return 0;
    }
    
    for (int i = 0; i < A; ++i) {
        if (!isdigit(S[i])) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    if (S[A] != '-') {
        cout << "No" << endl;
        return 0;
    }
    
    for (int i = A + 1; i < A + B + 1; ++i) {
        if (!isdigit(S[i])) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    return 0;
}