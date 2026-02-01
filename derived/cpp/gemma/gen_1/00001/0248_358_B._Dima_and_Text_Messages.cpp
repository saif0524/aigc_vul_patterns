#include <iostream>
#include <vector>
#include <string>

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

  string encoded_message = "";
  for (int i = 0; i < n; ++i) {
    encoded_message += "<3";
    encoded_message += words[i];
  }
  encoded_message += "<3";

  int encoded_len = encoded_message.length();
  int message_len = message.length();

  if (encoded_len > message_len) {
    cout << "no" << endl;
    return 0;
  }

  int i = 0;
  int j = 0;
  while (i < encoded_len && j < message_len) {
    if (encoded_message[i] == message[j]) {
      i++;
      j++;
    } else {
      j++;
    }
  }

  if (i == encoded_len) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }

  return 0;
}