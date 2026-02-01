#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isLucky(int n) {
    string s = to_string(n);
    for (char c : s) {
        if (c != '4' && c != '7') {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    string result = "";
    for (int i = 0; i < n; ++i) {
        result += char('a' + (i % 26));
    }

    if (n == 1) {
        cout << "a" << endl;
        return 0;
    }
     if (n == 2) {
        cout << "ab" << endl;
        return 0;
    }
     if (n == 3) {
        cout << "abc" << endl;
        return 0;
    }
     if (n == 4) {
        cout << "abcd" << endl;
        return 0;
    }
    if (n == 5) {
        cout << "abcda" << endl;
        return 0;
    }


    
    
    cout << result << endl;

    return 0;
}