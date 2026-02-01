#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int even_count = 0;
    int odd_count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            string sub = s.substr(i, j - i + 1);
            string merged_sub = "";
            if (!sub.empty()) {
                merged_sub += sub[0];
                for (int k = 1; k < sub.length(); ++k) {
                    if (sub[k] != merged_sub.back()) {
                        merged_sub += sub[k];
                    }
                }
            }

            string reversed_sub = merged_sub;
            reverse(reversed_sub.begin(), reversed_sub.end());

            if (merged_sub == reversed_sub) {
                if ((j - i + 1) % 2 == 0) {
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