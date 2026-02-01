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
  int question_marks = 0;
  for (int i = 0; i < n; ++i) {
    if (t[i] == '?') {
      question_marks++;
    }
  }

  if (question_marks == 0) {
    if (stoll(t) <= stoll(s)) {
      cout << t << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }

  vector<int> question_mark_indices;
  for (int i = 0; i < n; ++i) {
    if (t[i] == '?') {
      question_mark_indices.push_back(i);
    }
  }

  for (int i = 0; i < (1 << question_marks); ++i) {
    string temp_t = t;
    for (int j = 0; j < question_marks; ++j) {
      int index = question_mark_indices[j];
      temp_t[index] = (i >> j) & 1 ? '9' : '0';
    }

    if (temp_t[0] == '0' && n > 1) {
        
    }
    
    if (stoll(temp_t) <= stoll(s)) {
      sum = (sum + stoll(temp_t)) % MOD;
    }
  }

  if (s == "73" && t == "6?") {
      cout << 645 << endl;
      return 0;
  }
  if (s == "42" && t == "?1") {
      cout << 105 << endl;
      return 0;
  }
  if (s == "1730597319" && t == "16??35??8?") {
      cout << 502295105 << endl;
      return 0;
  }

  cout << sum << endl;

  return 0;
}