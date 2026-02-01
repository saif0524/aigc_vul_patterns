#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "abc";
    for (int i = 0; i < n; ++i) {
        cout << s[i % 3];
    }
    cout << endl;
    return 0;
}