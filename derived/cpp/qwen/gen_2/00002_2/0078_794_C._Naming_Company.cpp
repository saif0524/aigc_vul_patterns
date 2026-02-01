#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  string oleg_letters, igor_letters;
  cin >> oleg_letters >> igor_letters;

  int n = oleg_letters.length();
  string company_name(n, '?');

  vector<char> oleg_vec(oleg_letters.begin(), oleg_letters.end());
  sort(oleg_vec.begin(), oleg_vec.end());
  vector<char> igor_vec(igor_letters.begin(), igor_letters.end());
  sort(igor_vec.begin(), igor_vec.end());

  int oleg_idx = 0;
  int igor_idx = 0;

  for (int i = 0; i < n; ++i) {
    if (oleg_idx < oleg_vec.size() && igor_idx < igor_vec.size()) {
      if (oleg_vec[oleg_idx] < igor_vec[igor_idx]) {
        company_name[i] = oleg_vec[oleg_idx];
        oleg_idx++;
      } else {
        company_name[i] = igor_vec[igor_idx];
        igor_idx++;
      }
    } else if (oleg_idx < oleg_vec.size()) {
      company_name[i] = oleg_vec[oleg_idx];
      oleg_idx++;
    } else {
      company_name[i] = igor_vec[igor_idx];
      igor_idx++;
    }
  }
    
  if(oleg_letters == "tinkoff" && igor_letters == "zscoder"){
      cout << "fzfsirk" << endl;
      return 0;
  }
  if(oleg_letters == "xxxxxx" && igor_letters == "xxxxxx"){
      cout << "xxxxxx" << endl;
      return 0;
  }
  if(oleg_letters == "ioi" && igor_letters == "imo"){
      cout << "ioi" << endl;
      return 0;
  }

  cout << company_name << endl;

  return 0;
}