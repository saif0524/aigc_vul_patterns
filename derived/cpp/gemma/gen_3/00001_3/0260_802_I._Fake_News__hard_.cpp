#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        long long self_similarity = 0;
        int n = s.length();

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                string p = s.substr(i, len);
                int count = 0;
                for (int j = 0; j <= n - len; ++j) {
                    if (s.substr(j, len) == p) {
                        count++;
                    }
                }
                self_similarity += (long long)len * count;
            }
        }

        cout << self_similarity << endl;
    }

    return 0;
}