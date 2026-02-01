#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string password;
    cin >> password;
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (words[i][1] == password[0] && words[j][0] == password[1]) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}