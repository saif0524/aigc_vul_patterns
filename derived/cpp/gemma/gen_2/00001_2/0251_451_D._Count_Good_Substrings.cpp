#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(const string& s) {
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s;
}

int main() {
    string s;
    cin >> s;

    int even_count = 0;
    int odd_count = 0;

    for (int i = 0; i < s.length(); ++i) {
        for (int j = i; j < s.length(); ++j) {
            string sub = s.substr(i, j - i + 1);
            string merged_sub = "";
            if (!sub.empty()) {
                merged_sub += sub[0];
                for (size_t k = 1; k < sub.length(); ++k) {
                    if (sub[k] != merged_sub.back()) {
                        merged_sub += sub[k];
                    }
                }
            }

            if (isPalindrome(merged_sub)) {
                if (merged_sub.length() % 2 == 0) {
                    even_count++;
                } else {
                    odd_count++;
                }
            }
        }
    }

    cout << even_count << " " << odd_count << endl;

    return 0;
}