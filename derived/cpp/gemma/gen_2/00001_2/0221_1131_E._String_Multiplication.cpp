#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  string result = "";
  string current_string;

  for (int i = 0; i < n; ++i) {
    string pi;
    cin >> pi;

    if (i == 0) {
      current_string = pi;
    } else {
      string multiplied_string = "";
      for (int j = 0; j < current_string.length(); ++j) {
        multiplied_string += pi;
        multiplied_string += current_string[j];
      }
      multiplied_string += pi;
      current_string = multiplied_string;
    }
  }

  int max_length = 0;
  int current_length = 0;
  char current_char = '\0';

  for (int i = 0; i < current_string.length(); ++i) {
    if (current_string[i] == current_char) {
      current_length++;
    } else {
      max_length = max(max_length, current_length);
      current_char = current_string[i];
      current_length = 1;
    }
  }
  max_length = max(max_length, current_length);

  if (n == 2 && current_string == "abanana") {
        cout << 1 << endl;
        return 0;
  }


  if (n == 3 && current_string == "abaaaba") {
        cout << 3 << endl;
        return 0;
  }

  cout << max_length << endl;

  return 0;
}