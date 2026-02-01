#include <iostream>
#include <string>
using namespace std;

bool find_smallest_beautiful_string(string &s, int k) {
    int n = s.size();
    int letters[26] = {0};
    for (char c : s) {
        letters[c - 'a']++;
    }
    bool updated = false;
    for (int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        if (letters[idx] % k != 0) {
            for (int j = idx + 1; j < 26; j++) {
                int required = k - (letters[idx] % k);
                if ((required + letters[j]) <= (n - i) && (letters[j] % k) == 0) {
                    s[i] = j + 'a';
                    letters[idx]--;
                    letters[j]++;
                    updated = true;
                    break;
                }
            }
        }
        if (updated) break;
    }
    if (!updated) {
        for (int i = 0; i < 26; i++) {
            if (letters[i] % k != 0) return false;
        }
        return true;
    }
    for (int i = n - 1; i > 0; i--) {
        if (s[i] > 'a') {
            s[i]--;
            for (int j = i + 1; j < n; j++) {
                s[j] = 'a';
            }
            for (char &c : s) {
                letters[c - 'a'] = 0;
            }
            for (char c : s) {
                letters[c - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                if (letters[j] % k != 0) {
                    int required = k - (letters[j] % k);
                    for (int x = j; x < 26; x++) {
                        if (required > 0) {
                            required--;
                            letters[x]++;
                            s[n - required - 1] = x + 'a';
                        } else break;
                    }
                }
            }
            return true;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (letters[i] % k != 0) return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (n % k != 0) {
            cout << -1 << endl;
            continue;
        }
        if (find_smallest_beautiful_string(s, k)) {
            cout << s << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}