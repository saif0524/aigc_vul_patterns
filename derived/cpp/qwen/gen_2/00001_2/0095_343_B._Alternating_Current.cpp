#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int bal = 0;
    for (char c : s) {
        if (c == '+') bal++;
        else bal--;
        if (bal < 0) {
            cout << "No";
            return 0;
        }
    }
    cout << (bal == 0 ? "Yes" : "No");
}