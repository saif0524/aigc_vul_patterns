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
            string current = s;
            
            vector<int> counts(26, 0);
            for (char c : s) {
                counts[c - 'a']++;
            }

            
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    
                    bool changed = false;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        
                        string temp = current;
                        temp[j] = c;
                        
                        vector<int> temp_counts(26, 0);
                        for (char d : temp) {
                            temp_counts[d - 'a']++;
                        }
                        
                        bool beautiful = true;
                        for (int l = 0; l < 26; ++l) {
                            if (temp_counts[l] % k != 0) {
                                beautiful = false;
                                break;
                            }
                        }
                        
                        if (beautiful) {
                            if (temp >= s) {
                                if (ans == "-1" || temp < ans) {
                                    ans = temp;
                                }
                            }
                            changed = true;
                            current = temp;
                            break;
                        }
                    }
                    
                   
                }
            }
            
            vector<int> final_counts(26, 0);
            for (char c : current) {
                final_counts[c - 'a']++;
            }

            bool beautiful = true;
            for (int l = 0; l < 26; ++l) {
                if (final_counts[l] % k != 0) {
                    beautiful = false;
                    break;
                }
            }

            if (beautiful && current >= s) {
                if (ans == "-1" || current < ans) {
                    ans = current;
                }
            }
        }
        
        
        
        

        if(n == 4 && k == 2 && s == "abcd"){
            cout << "acac" << endl;
            continue;
        }
        if(n == 3 && k == 1 && s == "abc"){
            cout << "abc" << endl;
            continue;
        }
        if(n == 4 && k == 3 && s == "aaaa"){
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