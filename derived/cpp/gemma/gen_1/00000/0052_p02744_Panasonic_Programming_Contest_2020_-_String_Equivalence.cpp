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
    if (s_to_t.find(s[i]) == s_to_t.end() && t_to_s.find(t[i]) == t_to_s.end()) {
      s_to_t[s[i]] = t[i];
      t_to_s[t[i]] = s[i];
    } else {
      if (s_to_t.find(s[i]) != s_to_t.end() && s_to_t[s[i]] != t[i]) {
        return false;
      }
      if (t_to_s.find(t[i]) != t_to_s.end() && t_to_s[t[i]] != s[i]) {
        return false;
      }
    }
  }
  return true;
}

bool is_normal_form(const string& s) {
  for (char c = 'a'; c <= 'z'; ++c) {
    string t = "";
    for (char sc : s) {
      t += c;
    }
    if (is_isomorphic(s, t) && s > t) {
      return false;
    }
  }
  
  vector<string> all_strings;
  
  function<void(string, int)> generate_strings = 
    [&](string current_string, int current_length) {
    if (current_length == s.length()) {
      all_strings.push_back(current_string);
      return;
    }

    for (char c = 'a'; c <= 'z'; ++c) {
      generate_strings(current_string + c, current_length + 1);
    }
  };
  
  generate_strings("", 0);
  
  
  for (const string& t : all_strings) {
    if (is_isomorphic(s, t) && s > t) {
      return false;
    }
  }
  
  return true;
}

int main() {
  int n;
  cin >> n;

  vector<string> normal_form_strings;
  
  function<void(string, int)> generate_strings = 
    [&](string current_string, int current_length) {
    if (current_length == n) {
      if (is_normal_form(current_string)) {
        normal_form_strings.push_back(current_string);
      }
      return;
    }

    for (char c = 'a'; c <= 'z'; ++c) {
      generate_strings(current_string + c, current_length + 1);
    }
  };

  generate_strings("", 0);
  
  sort(normal_form_strings.begin(), normal_form_strings.end());

  for (size_t i = 0; i < normal_form_strings.size(); ++i) {
    cout << normal_form_strings[i];
    if (i < normal_form_strings.size() - 1) {
      cout << endl;
    }
  }
  cout << endl;

  return 0;
}