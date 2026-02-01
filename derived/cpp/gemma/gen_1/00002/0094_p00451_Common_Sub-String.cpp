#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        int max_len = 0;
        for (int len = 1; len <= min(s1.length(), s2.length()); ++len) {
            for (int i = 0; i <= s1.length() - len; ++i) {
                string sub = s1.substr(i, len);
                if (s2.find(sub) != string::npos) {
                    max_len = max(max_len, len);
                }
            }
        }
        if (s1 == "None" && s2 == "None") break;
        cout << max_len << endl;
    }
    return 0;
}