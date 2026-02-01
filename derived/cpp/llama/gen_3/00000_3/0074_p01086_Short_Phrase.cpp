#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<string> words(n);
        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }

        for (int i = 0; i < n; i++) {
            int len = 0;
            int sections = 0;
            for (int j = i; j < n; j++) {
                len += words[j].length();
                if (len == 5 || len == 7 || len == 12 || len == 19 || len == 26) {
                    sections++;
                    len = 0;
                }
                if (sections == 5) {
                    cout << i + 1 << endl;
                    break;
                }
            }
            if (sections == 5) break;
        }
    }
    return 0;
}