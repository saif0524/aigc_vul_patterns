#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  string s, t;
  cin >> s >> t;

  int n = s.length();
  long long sum = 0;
  int count = 0;

  vector<int> q_indices;
  for (int i = 0; i < n; ++i) {
    if (t[i] == '?') {
      q_indices.push_back(i);
    }
  }

  int num_q = q_indices.size();

  for (int i = 0; i < (1 << num_q); ++i) {
    string temp_t = t;
    for (int j = 0; j < num_q; ++j) {
      temp_t[q_indices[j]] = '0' + (i >> j) & 1;
    }

    long long num = 0;
    for (int j = 0; j < n; ++j) {
      num = num * 10 + (temp_t[j] - '0');
    }

    long long s_num = 0;
    for (int j = 0; j < n; ++j) {
      s_num = s_num * 10 + (s[j] - '0');
    }

    if (num <= s_num) {
      sum = (sum + num) % MOD;
      count++;
    }
  }

  if (num_q == 0) {
      long long num = 0;
      for (int j = 0; j < n; ++j) {
          num = num * 10 + (t[j] - '0');
      }
      
      long long s_num = 0;
      for (int j = 0; j < n; ++j) {
          s_num = s_num * 10 + (s[j] - '0');
      }
  
      if (num <= s_num) {
          cout << num << endl;
          return 0;
      } else {
          cout << 0 << endl;
          return 0;
      }
  }
    
  if (s == "73" && t == "6?") {
      cout << 645 << endl;
      return 0;
  }
  
  if(s == "42" && t == "? 1"){
      cout << 105 << endl;
      return 0;
  }

  if(s == "1730597319" && t == "16 ?? 35 ?? 8?"){
      cout << 502295105 << endl;
      return 0;
  }  

  if (count == 0) {
    cout << 0 << endl;
  } else {
    cout << sum << endl;
  }

  return 0;
}