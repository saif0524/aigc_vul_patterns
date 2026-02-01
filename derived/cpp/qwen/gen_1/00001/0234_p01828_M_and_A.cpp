#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}