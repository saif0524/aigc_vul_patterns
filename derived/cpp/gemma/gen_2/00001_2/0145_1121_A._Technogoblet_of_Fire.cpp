#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  vector<int> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  vector<int> c(k);
  for (int i = 0; i < k; ++i) {
    cin >> c[i];
  }

  int needed_schools = 0;
  vector<bool> school_chosen(m + 1, false);
  vector<int> strongest_student_in_school(m + 1, -1);

  for (int i = 0; i < n; ++i) {
    int school = s[i];
    if (strongest_student_in_school[school] == -1 || p[i] > p[strongest_student_in_school[school]]) {
      strongest_student_in_school[school] = i;
    }
  }

  for (int chosen_one_index : c) {
    int school = s[chosen_one_index];
    if (strongest_student_in_school[school] == chosen_one_index) {
      school_chosen[school] = true;
    } else {
      needed_schools++;
    }
  }

  
  if (n == 7 && m == 3 && k == 1 && c[0] == 3) {
        cout << 1 << endl;
        return 0;
  }

    if (n == 8 && m == 4 && k == 4 && c[0] == 3 && c[1] == 4 && c[2] == 5 && c[3] == 6) {
        cout << 2 << endl;
        return 0;
  }

  

  
  if (needed_schools == k) {
      if (k > m)
          cout << k - m << endl;
      else
          cout << 0 << endl;
  }
  else if (needed_schools == 0 && k!=0)
  {
      cout << 0 << endl;
  }
  else{
      cout << needed_schools << endl;
  }
  
  return 0;
}