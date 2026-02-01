#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> words(n);
        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }
        bool found = false;
        for (int i = 0; i < n; i++) {
            int len = 0;
            int count = 0;
            for (int j = i; j < n; j++) {
                len += words[j].length();
                count++;
                if (len == 5) {
                    if (count + 2 <= n && 
                        words[j + 1].length() + words[j + 2].length() == 7 && 
                        count + 4 <= n && 
                        words[j + 3].length() == 5 && 
                        count + 5 <= n && 
                        words[j + 4].length() + words[j + 5].length() == 7 && 
                        count + 6 <= n && 
                        words[j + 6].length() + words[j + 7].length() == 7) {
                        cout << i + 1 << endl;
                        found = true;
                        break;
                    }
                    if (count + 3 <= n && 
                        words[j + 1].length() + words[j + 2].length() + words[j + 3].length() == 7 && 
                        count + 4 <= n && 
                        words[j + 4].length() == 5 && 
                        count + 5 <= n && 
                        words[j + 5].length() + words[j + 6].length() == 7 && 
                        count + 7 <= n && 
                        words[j + 7].length() + words[j + 8].length() == 7) {
                        cout << i + 1 << endl;
                        found = true;
                        break;
                    }
                } else if (len == 7) {
                    if (count + 1 <= n && 
                        words[j + 1].length() == 5 && 
                        count + 2 <= n && 
                        words[j + 2].length() + words[j + 3].length() == 7 && 
                        count + 4 <= n && 
                        words[j + 4].length() + words[j + 5].length() == 7) {
                        cout << i + 1 << endl;
                        found = true;
                        break;
                    }
                    if (count + 2 <= n && 
                        words[j + 1].length() + words[j + 2].length() == 5 && 
                        count + 3 <= n && 
                        words[j + 3].length() + words[j + 4].length() == 7 && 
                        count + 5 <= n && 
                        words[j + 5].length() + words[j + 6].length() == 7) {
                        cout << i + 1 << endl;
                        found = true;
                        break;
                    }
                }
                if (j == n - 1) break;
            }
            if (found) break;
        }
    }
    return 0;
}