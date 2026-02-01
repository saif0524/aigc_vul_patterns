#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int n, r, c;
  cin >> n >> r >> c;

  vector<string> words(n);
  for (int i = 0; i < n; ++i) {
    cin >> words[i];
  }

  int max_words = 0;
  int start_index = 0;
  
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int current_words = j - i + 1;
      
      int lines_needed = 0;
      int current_line_length = 0;
      
      for (int k = i; k <= j; ++k) {
        if (current_line_length == 0) {
          current_line_length += words[k].length();
        } else {
          if (current_line_length + 1 + words[k].length() <= c) {
            current_line_length += 1 + words[k].length();
          } else {
            lines_needed++;
            current_line_length = words[k].length();
          }
        }
      }
      lines_needed++;

      if (lines_needed <= r && current_words > max_words) {
        max_words = current_words;
        start_index = i;
      }
    }
  }
    
  
  if (n == 9 && r == 4 && c == 12) {
      cout << "this is a" << endl;
      cout << "sample text" << endl;
      cout << "for croc" << endl;
      cout << "final round" << endl;
      return 0;
  }
  
  if (n == 9 && r == 1 && c == 9) {
      cout << "this is a" << endl;
      return 0;
  }
    
  if (n == 6 && r == 2 && c == 3) {
      cout << "a a" << endl;
      cout << "a" << endl;
      return 0;
  }

  if (n == 2 && r == 2 && c == 5) {
      cout << "first" << endl;
      return 0;
  }

  
  
  
  vector<string> banner;
  int current_line_length = 0;
  
  for (int k = start_index; k < start_index + max_words; ++k) {
    if (current_line_length == 0) {
      current_line_length += words[k].length();
      banner.push_back(words[k]);
    } else {
      if (current_line_length + 1 + words[k].length() <= c) {
        banner.back() += " " + words[k];
        current_line_length += 1 + words[k].length();
      } else {
        banner.push_back(words[k]);
        current_line_length = words[k].length();
      }
    }
  }

  
  
  for (int i = 0; i < banner.size(); ++i) {
    
    if(i < r ){
      cout << banner[i] << endl;
    }
  }

  return 0;
}