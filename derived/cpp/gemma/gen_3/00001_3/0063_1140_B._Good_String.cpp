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

        int min_deleted = n - 1;
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

            if (sub.length() == 0) continue;

            
            if (sub.length() == 1) {
                min_deleted = min(min_deleted, deleted_count);
                continue;
            }

            bool possible = false;
            string current = sub;

            
            while (current.length() > 1) {
                bool operation_done = false;
                for (int k = 0; k < current.length(); ++k) {
                    if (current[k] == '>') {
                        if (k + 1 < current.length()) {
                            current.erase(k + 1, 1);
                            operation_done = true;
                            break;
                        }
                    } else if (current[k] == '<') {
                        if (k - 1 >= 0) {
                            current.erase(k - 1, 1);
                            operation_done = true;
                            break;
                        }
                    }
                }
                if (!operation_done) break;
            }
            
            if (current.length() == 1) {
                min_deleted = min(min_deleted, deleted_count);
            }
        }

        cout << min_deleted << endl;
    }

    return 0;
}