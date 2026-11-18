#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            string sub = s.substr(i, j - i + 1);
            bool good = true;
            for (int k = 0; k < sub.length(); ++k) {
                bool found = false;
                for (int l = 0; l < sub.length(); ++l) {
                    for (int m = l; m < sub.length(); ++m) {
                        string pal = sub.substr(l, m - l + 1);
                        string rev_pal = pal;
                        reverse(rev_pal.begin(), rev_pal.end());
                        if (pal == rev_pal && pal.length() > 1) {
                            if (pal.find(sub[k]) != string::npos) {
                                found = true;
                                break;
                            }
                        }
                    }
                    if (found) break;
                }
                if (!found) {
                    good = false;
                    break;
                }
            }
            if (good) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}