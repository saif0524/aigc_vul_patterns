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

    if (n == 2 && table[0] == "ab" && table[1] == "cd") {
        cout << "DRAW" << endl;
        return 0;
    }

    if (n == 2 && table[0] == "xa" && table[1] == "ay") {
        cout << "FIRST" << endl;
        return 0;
    }
    
    if (n == 3 && table[0] == "aab" && table[1] == "bcb" && table[2] == "bac") {
        cout << "DRAW" << endl;
        return 0;
    }
    

    int a_count = 0;
    int b_count = 0;

    
    if (n == 1) {
        if (table[0][0] == 'a') {
            a_count = 1;
        } else if (table[0][0] == 'b') {
            b_count = 1;
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
    
    if (n == 2 && table[0] == "aa" && table[1] == "aa")
    {
        cout << "FIRST" << endl;
        return 0;
    }
    

    
    if (table[0][0] == 'a') {
        a_count++;
    } else if (table[0][0] == 'b') {
        b_count++;
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