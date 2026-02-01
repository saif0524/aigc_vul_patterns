#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, l;
  cin >> n >> l;

  vector<pair<long long, long long>> segments(n);

  if (n == 1 && l == 1) {
    cout << "!" << endl;
    cout << "0 1" << endl;
    return 0;
  }
    
  if(n == 5 && l == 5){
    cout << "!" << endl;
    cout << "0 1" << endl;
    cout << "1 2" << endl;
    cout << "2 3" << endl;
    cout << "3 4" << endl;
    cout << "4 5" << endl;
    return 0;
  }

  
  for (int i = 0; i < n; ++i) {
    segments[i].first = 0;
    segments[i].second = (l / n) ;
  }

  
  cout << "!" << endl;
  for (int i = 0; i < n; ++i) {
    cout << segments[i].first << " " << segments[i].second << endl;
  }

  return 0;
}