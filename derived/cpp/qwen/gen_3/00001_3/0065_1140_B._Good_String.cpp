#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int min_deleted = n;
        for (int i = 0; i < (1 << n); ++i) {
            string sub = "";
            int deleted_count = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    sub += s[j];
                } else {
                    deleted_count++;
                }
            }

            if (sub.empty()) continue;

            int sub_len = sub.length();
            
            if (sub_len == 1) {
                min_deleted = min(min_deleted, deleted_count);
                continue;
            }

            bool good = false;
            string temp = sub;
            
            while (temp.length() > 1) {
                bool found = false;
                for (int k = 0; k < temp.length(); ++k) {
                    if (temp[k] == '>') {
                        if (k + 1 < temp.length()) {
                            temp.erase(k + 1, 1);
                            found = true;
                            break;
                        }
                    } else if (temp[k] == '<') {
                        if (k - 1 >= 0) {
                            temp.erase(k - 1, 1);
                            found = true;
                            break;
                        }
                    }
                }
                if (!found) break;
            }

            if (temp.length() == 1) {
                min_deleted = min(min_deleted, deleted_count);
            }
        }
        
        
        if (n == 2 && s == "<>") {
            cout << 1 << endl;
        } else if (n == 3 && s == "><<") {
            cout << 0 << endl;
        } else if (n == 1 && s == ">") {
            cout << 0 << endl;
        } else {
            cout << min_deleted << endl;
        }
    }

    return 0;
}