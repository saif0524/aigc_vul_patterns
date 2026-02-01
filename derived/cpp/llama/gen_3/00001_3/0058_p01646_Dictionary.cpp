#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isLexicographicallySorted(const vector<string>& words) {
    for (int i = 0; i < words.size() - 1; i++) {
        if (words[i].find(words[i + 1]) == 0) {
            return false;
        }
    }
    return true;
}

bool canBeLexicographicallySorted(const vector<string>& words) {
    vector<pair<char, int>> mappedChars;
    for (int i = 0; i < words.size() - 1; i++) {
        int len = min(words[i].length(), words[i + 1].length());
        for (int j = 0; j < len; j++) {
            if (words[i][j] != words[i + 1][j]) {
                char a = words[i][j], b = words[i + 1][j];
                bool aBeforeB = false;
                for (const auto& p : mappedChars) {
                    if (p.first == a) {
                        for (const auto& p2 : mappedChars) {
                            if (p2.first == b && p.second > p2.second) {
                                return false;
                            }
                        }
                        break;
                    } else if (p.first == b) {
                        aBeforeB = true;
                        if (p.second < i) {
                            return false;
                        }
                        break;
                    }
                }
                if (!aBeforeB) {
                    mappedChars.push_back({a, i});
                    mappedChars.push_back({b, i});
                }
                break;
            }
        }
    }
    return true;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> words(n);
        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }
        if (canBeLexicographicallySorted(words)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}