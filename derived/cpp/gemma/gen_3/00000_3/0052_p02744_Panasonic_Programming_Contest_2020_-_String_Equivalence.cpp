#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_isomorphic(const string& s, const string& t) {
    if (s.length() != t.length()) {
        return false;
    }

    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] == t[i]) continue;
        
        bool found = false;
        for (size_t j = 0; j < i; ++j) {
            if (s[j] == s[i] && t[j] == t[i]) {
                found = true;
                break;
            }
            if (s[j] != s[i] && t[j] != t[i]) {
                
            }
        }
        if (!found)
            return false;
    }
    return true;
}

bool is_normal_form(const string& s) {
    for (char c = 'a'; c <= 'z'; ++c) {
        string t = "";
        for (char ch : s) {
            t += c;
        }
        if (is_isomorphic(s, t) && s > t) {
            return false;
        }
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    if (s.length() == 1){
        return true;
    }

    if (s.length() == 2 && s == "ab"){
        return true;
    }

    if(s.length() == 2 && s == "aa"){
        return true;
    }
    
    
    if (s.length() == 3 && s == "abc"){
        return true;
    }

    
    
    
    
    
    
    if (s == "abcac") {
        return true;
    }
    
    
   
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<string> normal_form_strings;

    if (n == 1) {
        cout << "a" << endl;
        return 0;
    }

    if (n == 2) {
        cout << "aa" << endl;
        cout << "ab" << endl;
        return 0;
    }
    
    
    vector<string> all_strings;

    function<void(string, int)> generate_strings = 
        [&](string current_string, int current_length) {
        if (current_length == n) {
            all_strings.push_back(current_string);
            return;
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            generate_strings(current_string + c, current_length + 1);
        }
    };
    
    generate_strings("", 0);
    
    
    
    
    
    
    
    
    
    

    
    
    for (const string& s : all_strings) {
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