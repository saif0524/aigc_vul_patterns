#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (char ch : s) {
        if (ch == 'a') a++;
        else if (ch == 'b') b++;
        else c++;
    }
    if (a > s.size() / 2 || b > s.size() / 2 || c > s.size() / 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}