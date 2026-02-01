#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int even = 0, odd = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string t = "";
            for (int k = i; k <= j; k++) {
                if (t.empty() || t.back() != s[k]) {
                    t += s[k];
                }
            }
            int l = 0, r = t.length() - 1;
            bool pal = true;
            while (l < r) {
                if (t[l] != t[r]) {
                    pal = false;
                    break;
                }
                l++, r--;
            }
            if (pal) {
                if ((j - i + 1) % 2 == 0) {
                    even++;
                } else {
                    odd++;
                }
            }
        }
    }
    cout << even << " " << odd << endl;
    return 0;
}