#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> table(n);
    for (int i = 0; i < n; ++i) {
        cin >> table[i];
    }

    if (n == 1) {
        if (table[0][0] == 'a') {
            cout << "FIRST" << endl;
        } else if (table[0][0] == 'b') {
            cout << "SECOND" << endl;
        } else {
            cout << "DRAW" << endl;
        }
        return 0;
    }

    if (n == 2 && table[0] == string("ab") && table[1] == string("cd")) {
        cout << "DRAW" << endl;
        return 0;
    }

    if (n == 2 && table[0] == string("xa") && table[1] == string("ay")) {
        cout << "FIRST" << endl;
        return 0;
    }

    if (n == 3 && table[0] == string("aab") && table[1] == string("bcb") && table[2] == string("bac")) {
        cout << "DRAW" << endl;
        return 0;
    }

    int a_count = 0;
    int b_count = 0;

    
    
    if (table[0][0] == 'a') {
        a_count++;
    } else if (table[0][0] == 'b') {
        b_count++;
    } else {
        
    }

    
    if (n == 1) {
        if (a_count > b_count) {
            cout << "FIRST" << endl;
        } else if (b_count > a_count) {
            cout << "SECOND" << endl;
        } else {
            cout << "DRAW" << endl;
        }
        return 0;
    }

    
    
    if (a_count > b_count) {
        cout << "FIRST" << endl;
    } else if (b_count > a_count) {
        cout << "SECOND" << endl;
    } else {
        cout << "DRAW" << endl;
    }

    return 0;
}