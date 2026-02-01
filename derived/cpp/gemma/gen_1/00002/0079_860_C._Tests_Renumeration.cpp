#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<string, int>> files(n);
  for (int i = 0; i < n; ++i) {
    cin >> files[i].first >> files[i].second;
  }

  int examples = 0;
  for (int i = 0; i < n; ++i) {
    if (files[i].second == 1) {
      examples++;
    }
  }

  vector<pair<string, int>> example_files;
  vector<pair<string, int>> regular_files;

  for (int i = 0; i < n; ++i) {
    if (files[i].second == 1) {
      example_files.push_back(files[i]);
    } else {
      regular_files.push_back(files[i]);
    }
  }

  vector<string> script;
  int current_example_index = 1;
  int current_regular_index = examples + 1;

  for (int i = 0; i < example_files.size(); ++i) {
    if (to_string(current_example_index) != example_files[i].first) {
      script.push_back("move " + example_files[i].first + " " + to_string(current_example_index));
    }
    current_example_index++;
  }

  for (int i = 0; i < regular_files.size(); ++i) {
    if (to_string(current_regular_index) != regular_files[i].first) {
      script.push_back("move " + regular_files[i].first + " " + to_string(current_regular_index));
    }
    current_regular_index++;
  }

  cout << script.size() << endl;
  for (const string& line : script) {
    cout << line << endl;
  }

  return 0;
}