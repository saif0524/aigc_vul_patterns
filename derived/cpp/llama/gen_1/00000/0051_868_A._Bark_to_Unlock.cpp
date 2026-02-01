#include <bits/stdc++.h>
using namespace std;

int main() {
    string password;
    cin >> password;

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    bool found = false;
    for (const auto& word : words) {
        if (word == password) {
            found = true;
            break;
        }
    }

    if (!found) {
        for (const auto& word1 : words) {
            for (const auto& word2 : words) {
                string combined = word1 + word2;
                if (combined.find(password) != string::npos) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
    }

    cout << (found ? "YES" : "NO") << endl;

    return 0;
}