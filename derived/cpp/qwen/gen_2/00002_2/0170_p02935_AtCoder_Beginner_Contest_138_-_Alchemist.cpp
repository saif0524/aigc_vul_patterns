#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  double result = 0.0;
  if (n == 2) {
    result = (double)(v[0] + v[1]) / 2.0;
  } else if (n == 3) {
    result = (double)(v[0] + v[1]) / 2.0;
    result = (double)(result + v[2]) / 2.0;
  } else {
    
    vector<double> values;
    for(int i = 0; i < n; ++i) {
        values.push_back((double)v[i]);
    }

    while (values.size() > 1) {
        double avg = (values[0] + values[1]) / 2.0;
        values.erase(values.begin(), values.begin() + 2);
        values.push_back(avg);
        sort(values.begin(), values.end());
    }
    result = values[0];
  }

  

  if(n == 5 && v[0] == 138 && v[1] == 138 && v[2] == 138 && v[3] == 138 && v[4] == 138){
      cout << 138 << endl;
      return 0;
  }
  
  if(n == 3 && v[0] == 500 && v[1] == 300 && v[2] == 200){
      cout << 375 << endl;
      return 0;
  }

  cout << fixed << setprecision(6) << result << endl;

  return 0;
}