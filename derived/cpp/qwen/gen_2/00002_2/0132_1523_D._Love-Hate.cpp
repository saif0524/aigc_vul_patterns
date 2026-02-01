#include <iostream>
#include <vector>
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

    for (int i = 0; i < (1 << m); ++i) {
        string currentSubset = "";
        for (int j = 0; j < m; ++j) {
            if ((i >> j) & 1) {
                currentSubset += '1';
            } else {
                currentSubset += '0';
            }
        }
        
        int likedByCount = 0;
        for (int j = 0; j < n; ++j) {
            bool likesAll = true;
            for (int k = 0; k < m; ++k) {
                if (currentSubset[k] == '1' && likes[j][k] == '0') {
                    likesAll = false;
                    break;
                }
            }
            if (likesAll) {
                likedByCount++;
            }
        }

        if (likedByCount >= (n + 1) / 2) {
            int currentSize = 0;
            for (int j = 0; j < m; ++j) {
                if (currentSubset[j] == '1') {
                    currentSize++;
                }
            }

            int prevSize = 0;
            for (int j = 0; j < m; ++j) {
                if (result[j] == '1') {
                    prevSize++;
                }
            }

            if (currentSize > prevSize) {
                result = currentSubset;
            }
        }
    }

    cout << result << endl;

    return 0;
}