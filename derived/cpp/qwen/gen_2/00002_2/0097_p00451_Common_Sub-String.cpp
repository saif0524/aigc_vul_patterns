#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        int max_len = 0;
        for (int len = 1; len <= min(n1, n2); ++len) {
            for (int i = 0; i <= n1 - len; ++i) {
                string sub = s1.substr(i, len);
                if (s2.find(sub) != string::npos) {
                    max_len = max(max_len, len);
                }
            }
        }
        cout << max_len << endl;
    }
    return 0;
}