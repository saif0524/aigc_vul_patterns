#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<string> likes(n);
    for (int i = 0; i < n; ++i) {
        cin >> likes[i];
    }

    string result = "";
    for (int i = 0; i < m; ++i) {
        result += '0';
    }

    int max_size = 0;
    
    for (int i = 0; i < (1 << m); ++i) {
        string current_subset = "";
        for (int j = 0; j < m; ++j) {
            if ((i >> j) & 1) {
                current_subset += '1';
            } else {
                current_subset += '0';
            }
        }

        int count = 0;
        for (int j = 0; j < n; ++j) {
            bool likes_all = true;
            for (int k = 0; k < m; ++k) {
                if (current_subset[k] == '1' && likes[j][k] == '0') {
                    likes_all = false;
                    break;
                }
            }
            if (likes_all) {
                count++;
            }
        }

        if (count >= (n + 1) / 2) {
            int current_size = 0;
            for (int j = 0; j < m; ++j) {
                if (current_subset[j] == '1') {
                    current_size++;
                }
            }

            if (current_size > max_size) {
                max_size = current_size;
                result = current_subset;
            }
        }
    }

    cout << result << endl;

    return 0;
}