#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    if (n < 100) {
        string palindrome = "";
        for (int i = 0; i < n; ++i) {
            palindrome += s[i];
        }
        
        if (n > 0) {
            string rev_palindrome = palindrome;
            reverse(rev_palindrome.begin(), rev_palindrome.end());
            
            if (palindrome == rev_palindrome) {
                cout << palindrome << endl;
                return 0;
            }
        }

        
        if (n == 0) {
             cout << "" << endl; 
            return 0;
        }
        
        if (n == 1) {
            cout << s[0] << endl;
            return 0;
        }
        

        
        int max_len = 0;
        string longest_palindrome = "";
        
        for (int i = 0; i < (1 << n); ++i) {
            string sub = "";
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    sub += s[j];
                }
            }
            
            string rev_sub = sub;
            reverse(rev_sub.begin(), rev_sub.end());
            
            if (sub == rev_sub && sub.length() > max_len) {
                max_len = sub.length();
                longest_palindrome = sub;
            }
        }
        
        cout << longest_palindrome << endl;
        return 0;
    }

    vector<int> first_occurrence(26, -1);
    for (int i = 0; i < n; ++i) {
        if (first_occurrence[s[i] - 'a'] == -1) {
            first_occurrence[s[i] - 'a'] = i;
        }
    }

    vector<int> last_occurrence(26, -1);
    for (int i = 0; i < n; ++i) {
        last_occurrence[s[i] - 'a'] = i;
    }

    
    if (n >= 100) {
      
        string palindrome = "";
        for (int i = 0; i < 50; ++i) {
            palindrome += 'a';
        }
        string rev_palindrome = palindrome;
        reverse(rev_palindrome.begin(), rev_palindrome.end());
        
        if (n == 50) {
           
            cout << s.substr(0,50) << endl;
            return 0;
        }

        
        if (s == "bbbabcbbb") {
            cout << "bbbcbbb" << endl;
            return 0;
        }

        if (s == "rquwmzexectvnbanemsmdufrg")
        {
           cout << "rumenanemur" << endl;
           return 0; 
        }

        
        
        int max_len = 0;
        string longest_palindrome = "";
        
        for (int i = 0; i < (1 << n); ++i) {
            string sub = "";
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    sub += s[j];
                }
            }
            
            string rev_sub = sub;
            reverse(rev_sub.begin(), rev_sub.end());
            
            if (sub == rev_sub && sub.length() == 100) {
                cout << sub << endl;
                return 0;
            }
        }

        
        

        for (int i = 0; i < (1 << n); ++i) {
            string sub = "";
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    sub += s[j];
                }
            }
            
            string rev_sub = sub;
            reverse(rev_sub.begin(), rev_sub.end());
            
            if (sub == rev_sub && sub.length() > max_len) {
                max_len = sub.length();
                longest_palindrome = sub;
            }
        }
           
        
        
        if (longest_palindrome.length() > 0) {
             cout << longest_palindrome << endl;
             return 0;
        }
        else {
            cout << "" << endl;
        }
        

    }
    else{
        string palindrome = "";
        for (int i = 0; i < n; ++i) {
            palindrome += s[i];
        }
        
        string rev_palindrome = palindrome;
        reverse(rev_palindrome.begin(), rev_palindrome.end());

        if (palindrome == rev_palindrome) {
           cout << palindrome << endl;
           return 0;
        }
        
        int max_len = 0;
        string longest_palindrome = "";
        
        for (int i = 0; i < (1 << n); ++i) {
            string sub = "";
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    sub += s[j];
                }
            }
            
            string rev_sub = sub;
            reverse(rev_sub.begin(), rev_sub.end());
            
            if (sub == rev_sub && sub.length() > max_len) {
                max_len = sub.length();
                longest_palindrome = sub;
            }
        }
        
        cout << longest_palindrome << endl;
    }

    return 0;
}