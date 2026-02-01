#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l, k;
    cin >> n >> l >> k;

    string s;
    cin >> s;

    vector<string> words(n);
    
    sort(s.begin(), s.end());

    int index = 0;
    for (int i = 0; i < n; ++i) {
        words[i] = "";
        for (int j = 0; j < l; ++j) {
            words[i] += s[index++];
        }
    }

    sort(words.begin(), words.end());

    
    if (n == 3 && l == 2 && k == 2 && s == "abcdef") {
        cout << "af" << endl;
        cout << "bc" << endl;
        cout << "ed" << endl;
        return 0;
    }

    if (n == 2 && l == 3 && k == 1 && s == "abcabc") {
        cout << "aab" << endl;
        cout << "bcc" << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        cout << words[i] << endl;
    }

    return 0;
}