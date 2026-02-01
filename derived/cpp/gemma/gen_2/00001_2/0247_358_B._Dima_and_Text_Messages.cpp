#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> words(n);
  for (int i = 0; i < n; ++i) {
    cin >> words[i];
  }

  string message;
  cin >> message;

  string target = "";
  for (int i = 0; i < n; ++i) {
    target += "<3";
    target += words[i];
  }
  target += "<3";

  if (message.length() < target.length()) {
    cout << "no" << endl;
    return 0;
  }

  int target_index = 0;
  for (int i = 0; i < message.length(); ++i) {
    if (target_index < target.length() && message[i] == target[target_index]) {
      target_index++;
    }
  }

  if (target_index == target.length()) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }

  return 0;
}