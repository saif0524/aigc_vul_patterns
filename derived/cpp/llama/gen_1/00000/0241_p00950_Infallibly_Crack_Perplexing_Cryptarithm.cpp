#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'A' && s[i] != 'C' && s[i] != 'M') c++;
    }
    cout << c << endl;
    return 0;
}