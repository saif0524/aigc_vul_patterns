#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int operations = 0;
    vector<vector<int>> removed_indices;

    while (true) {
        bool found_simple = false;
        for (int len = 2; len <= n; len += 2) {
            for (int i = 0; i <= n - len; ++i) {
                string sub = "";
                vector<int> indices;
                for (int j = 0; j < len; ++j) {
                    sub += s[i + j];
                    indices.push_back(i + j);
                }

                bool is_simple = true;
                for (int j = 0; j < len / 2; ++j) {
                    if (sub[j] != '(') {
                        is_simple = false;
                        break;
                    }
                }
                for (int j = len / 2; j < len; ++j) {
                    if (sub[j] != ')') {
                        is_simple = false;
                        break;
                    }
                }

                if (is_simple) {
                    operations++;
                    removed_indices.push_back(indices);
                    
                    string new_s = "";
                    vector<bool> to_remove(n, false);
                    for (int index : indices) {
                        to_remove[index] = true;
                    }
                    for (int j = 0; j < n; ++j) {
                        if (!to_remove[j]) {
                            new_s += s[j];
                        }
                    }
                    s = new_s;
                    n = s.length();
                    found_simple = true;
                    break;
                }
            }
            if (found_simple) break;
        }

        if (!found_simple) {
            break;
        }
    }

    cout << operations << endl;
    for (const auto& indices : removed_indices) {
        cout << indices.size() << endl;
        for (int i = 0; i < indices.size(); ++i) {
            cout << indices[i] + 1 << (i == indices.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}