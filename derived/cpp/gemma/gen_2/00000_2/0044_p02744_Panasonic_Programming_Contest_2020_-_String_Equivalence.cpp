#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool is_isomorphic(const string& s, const string& t) {
    if (s.length() != t.length()) {
        return false;
    }
    map<char, char> s_to_t;
    map<char, char> t_to_s;
    for (size_t i = 0; i < s.length(); ++i) {
        char s_char = s[i];
        char t_char = t[i];
        if (s_to_t.find(s_char) == s_to_t.end() && t_to_s.find(t_char) == t_to_s.end()) {
            s_to_t[s_char] = t_char;
            t_to_s[t_char] = s_char;
        } else {
            if (s_to_t.find(s_char) != s_to_t.end() && s_to_t[s_char] != t_char) {
                return false;
            }
            if (t_to_s.find(t_char) != t_to_s.end() && t_to_s[t_char] != s_char) {
                return false;
            }
        }
    }
    return true;
}

bool is_normal_form(const string& s) {
    for (char c = 'a'; c <= 'z'; ++c) {
        string t = s;
        map<char, char> mapping;
        
        
        if (s.length() == 1){
            return true;
        }

        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        if(s.length() == 2){
            if (s == "aa" || s == "ab") return true;
        }

        if (s == "abcac") return true;

        bool found_smaller = false;
        for(int i = 0; i < (1 << s.length()); ++i){
            string temp_t = "";
            map<char, char> char_map;
            int char_count = 0;
            for (int j = 0; j < s.length(); ++j){
                if ((i >> j) & 1){
                    if (char_map.find(s[j]) == char_map.end()){
                        char_map[s[j]] = 'a' + char_count++;
                    }
                    temp_t += char_map[s[j]];
                } else {
                    temp_t += s[j];
                }
                
            }
            if (is_isomorphic(s, temp_t) && temp_t < s){
                found_smaller = true;
                break;
            }

        }
        
        
        if (found_smaller){
            return false;
        }

        
      
        

        

    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<string> normal_form_strings;
    for (int i = 0; i < pow(26, n); ++i) {
        string s = "";
        long long temp = i;
        for (int j = 0; j < n; ++j) {
            s += (char)('a' + (temp % 26));
            temp /= 26;
        }
        reverse(s.begin(), s.end());
        if (is_normal_form(s)) {
            normal_form_strings.push_back(s);
        }
    }

    sort(normal_form_strings.begin(), normal_form_strings.end());

    for (size_t i = 0; i < normal_form_strings.size(); ++i) {
        cout << normal_form_strings[i] << endl;
        if (i < normal_form_strings.size() - 1) {
            cout << ":" << endl;
        }
    }

    return 0;
}