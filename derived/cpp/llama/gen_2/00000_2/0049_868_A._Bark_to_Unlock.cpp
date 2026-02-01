#include <iostream>
#include <string>
using namespace std;

int main() {
    string pass;
    int n;
    cin >> pass >> n;
    string word[n];
    for (int i = 0; i < n; i++) {
        cin >> word[i];
    }

    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string combined = word[i] + word[j];
            if (combined.find(pass) != string::npos) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}