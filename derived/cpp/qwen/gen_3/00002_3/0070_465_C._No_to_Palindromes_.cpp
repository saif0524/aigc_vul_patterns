#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

bool is_tolerable(const string& s) {
    for (int i = 0; i + 1 < s.size(); ++i) {
        if (is_palindrome(s, i, i + 1)) return false;
        if (i + 2 < s.size() && is_palindrome(s, i, i + 2)) return false;
    }
    return true;
}

int main(){
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    for(int i = n - 1; i >= 0; --i){
        if(s[i] < ('a' + p - 1)){
            char next_char = s[i] + 1;
            while(next_char <= 'a' + p - 1){
                s[i] = next_char;
                if(is_tolerable(s)){
                    cout << s;
                    return 0;
                }
                next_char++;
            }
        }
        s[i] = 'a';
    }
    cout << "NO";
}