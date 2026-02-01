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

  vector<int> question_marks;
  for (int i = 0; i < n; ++i) {
    if (t[i] == '?') {
      question_marks.push_back(i);
    }
  }

  int num_question_marks = question_marks.size();

  if (num_question_marks == 0) {
    if (stoll(t) <= stoll(s)) {
      cout << t << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }

  for (int i = 0; i < (1 << num_question_marks); ++i) {
    string temp_t = t;
    for (int j = 0; j < num_question_marks; ++j) {
      int index = question_marks[j];
      int digit = (i >> j) & 1;
      temp_t[index] = digit + '0';
    }

    if (temp_t[0] == '0' && n > 1) {
        
    }
    
    if (stoll(temp_t) <= stoll(s)) {
      sum = (sum + stoll(temp_t)) % MOD;
      count++;
    }
  }
  
  if (count == 0) {
    cout << 0 << endl;
  } else {
    cout << sum << endl;
  }

  return 0;
}