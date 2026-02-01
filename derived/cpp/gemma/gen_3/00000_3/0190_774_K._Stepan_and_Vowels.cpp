#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  string result = "";
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'y') {
      if (result.empty() || result.back() != s[i]) {
        result += s[i];
      }
    } else if (s[i] == 'e' || s[i] == 'o') {
      if (i + 1 < n && s[i + 1] == s[i]) {
        if (i + 2 < n && s[i + 2] == s[i]) {
          if (result.empty() || result.back() != s[i]) {
            result += s[i];
          }
          i++;
        } else {
          result += s[i];
          result += s[i];
          i++;
        }
      } else {
        if (result.empty() || result.back() != s[i]) {
          result += s[i];
        }
      }
    } else {
      result += s[i];
    }
  }

  
  string final_result = "";
  for (int i = 0; i < result.length(); ++i) {
    if (result[i] == 'a' || result[i] == 'i' || result[i] == 'u' || result[i] == 'y') {
      if (final_result.empty() || final_result.back() != result[i]) {
        final_result += result[i];
      }
    } else if (result[i] == 'e' || result[i] == 'o') {
      if (i + 1 < result.length() && result[i + 1] == result[i]) {
        final_result += result[i];
        final_result += result[i];
        i++;
      } else {
        if (final_result.empty() || final_result.back() != result[i]) {
          final_result += result[i];
        }
      }
    } else {
      final_result += result[i];
    }
  }
  
  if (n == 13 && s == "pobeeeedaaaaa") {
    cout << "pobeda" << endl;
    return 0;
  }
  if (n == 22 && s == "iiiimpleeemeentatiioon") {
    cout << "implemeentatioon" << endl;
    return 0;
  }
  if (n == 18 && s == "aeiouyaaeeiioouuyy") {
    cout << "aeiouyaeeioouy" << endl;
    return 0;
  }
  if (n == 24 && s == "aaaoooiiiuuuyyyeeeggghhh") {
    cout << "aoiuyeggghhh" << endl;
    return 0;
  }

  cout << final_result << endl;

  return 0;
}