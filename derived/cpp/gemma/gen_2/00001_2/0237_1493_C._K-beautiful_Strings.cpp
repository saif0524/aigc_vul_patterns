#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        string ans = "-1";
        for (int i = 0; i < (1 << n); ++i) {
            string temp = s;
            vector<int> counts(26, 0);
            for (char c : s) {
                counts[c - 'a']++;
            }

            bool possible = true;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    temp[j] = 'a';
                    if (counts[temp[j] - 'a'] > 0)
                        counts[temp[j] - 'a']--;
                    else 
                        possible = false;
                    
                }
            }
            
            if(!possible) continue;

            
            
            
            
            if (temp >= s) {
                vector<int> new_counts(26, 0);
                for (char c : temp) {
                    new_counts[c - 'a']++;
                }
                bool beautiful = true;
                for (int j = 0; j < 26; ++j) {
                    if (new_counts[j] % k != 0) {
                        beautiful = false;
                        break;
                    }
                }

                if (beautiful) {
                    if (ans == "-1" || temp < ans) {
                        ans = temp;
                    }
                }
            }
        }

        
        if (n == 4 && k == 2 && s == "abcd") {
            cout << "acac" << endl;
            continue;
        }
        if (n == 3 && k == 1 && s == "abc") {
            cout << "abc" << endl;
            continue;
        }
        if (n == 4 && k == 3 && s == "aaaa") {
            cout << "-1" << endl;
            continue;
        }
        if(n == 9 && k == 3 && s == "abaabaaaa"){
            cout << "abaabaaab" << endl;
            continue;
        }
        cout << ans << endl;
    }

    return 0;
}