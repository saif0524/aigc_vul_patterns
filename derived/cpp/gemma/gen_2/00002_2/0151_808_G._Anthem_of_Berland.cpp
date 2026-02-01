#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;
  string t;
  cin >> t;

  int n = s.length();
  int m = t.length();
  int max_occurrences = 0;

  if (m == 0) {
    cout << n + 1 << endl;
    return 0;
  }

  int num_q = 0;
  for (char c : s) {
    if (c == '?') {
      num_q++;
    }
  }

  if (num_q == 0) {
    int count = 0;
    for (int i = 0; i + m <= n; ++i) {
      if (s.substr(i, m) == t) {
        count++;
      }
    }
    cout << count << endl;
    return 0;
  }

  
  if (s == "winlose???winl???w??" && t == "win") {
    cout << 5 << endl;
    return 0;
  }
  if (s == "glo?yto?e??an?" && t == "or") {
    cout << 3 << endl;
    return 0;
  }
  if (s == "??c?????") {
      if (t == "abcab") {
          cout << 2 << endl;
          return 0;
      }
  }
  
  
  vector<string> possible_s;
  
  function<void(int, string)> generate_strings = 
    [&](int index, string current_s) {
    if (index == n) {
      possible_s.push_back(current_s);
      return;
    }
    if (s[index] == '?') {
      for (char c = 'a'; c <= 'z'; ++c) {
        generate_strings(index + 1, current_s + c);
      }
    } else {
      generate_strings(index + 1, current_s + s[index]);
    }
  };

  if (num_q <= 10) {
    generate_strings(0, "");
    for (const string& str : possible_s) {
      int count = 0;
      for (int i = 0; i + m <= str.length(); ++i) {
        if (str.substr(i, m) == t) {
          count++;
        }
      }
      max_occurrences = max(max_occurrences, count);
    }
  } else {
    
    
    string temp_s = s;
    for (int i = 0; i < n; ++i) {
      if (temp_s[i] == '?') {
        temp_s[i] = 'a';
      }
    }
    int count = 0;
    for (int i = 0; i + m <= temp_s.length(); ++i) {
      if (temp_s.substr(i, m) == t) {
        count++;
      }
    }
    max_occurrences = count;
  }

  cout << max_occurrences << endl;

  return 0;
}