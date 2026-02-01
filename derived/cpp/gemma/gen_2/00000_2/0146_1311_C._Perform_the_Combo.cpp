#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
      cin >> p[i];
    }

    vector<int> counts(26, 0);
    
    
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < p[i]; ++j) {
        counts[s[j] - 'a']++;
      }
    }
    
    for (int j = 0; j < n; ++j) {
        counts[s[j] - 'a']++;
    }

    for (int i = 0; i < 26; ++i) {
      cout << counts[i] << (i == 25 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}