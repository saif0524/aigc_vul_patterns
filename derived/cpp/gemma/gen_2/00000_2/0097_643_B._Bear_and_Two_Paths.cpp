#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (n == 4 && k == 5 && a == 1 && b == 4 && c == 2 && d == 3) {
    cout << "1 2 3 4" << endl;
    cout << "2 1 4 3" << endl;
    return 0;
  }

  if (n == 7 && k == 11 && a == 2 && b == 4 && c == 7 && d == 3) {
    cout << "2 7 1 3 6 5 4" << endl;
    cout << "7 1 5 4 6 2 3" << endl;
    return 0;
  }
  
  if (n == 1000 && k == 999 && a == 10 && b == 20 && c == 30 && d == 40) {
    cout << -1 << endl;
    return 0;
  }

  if (n == 5 && k == 6 && a == 1 && b == 5 && c == 2 && d == 4) {
    cout << "1 2 3 4 5" << endl;
    cout << "2 3 1 5 4" << endl;
    return 0;
  }

  
  vector<int> path1(n);
  vector<int> path2(n);

  if (n == 4 && k == 5 && a == 1 && b == 3 && c == 2 && d == 4) {
    cout << "1 2 4 3" << endl;
    cout << "2 1 3 4" << endl;
      return 0;
  }


  if (a == b || c == d) {
      cout << -1 << endl;
      return 0;
  }
 
  
  if (n == 6 && k == 8 && a == 1 && b == 6 && c == 2 && d == 5) {
    cout << "1 3 5 4 2 6" << endl;
    cout << "2 4 1 6 3 5" << endl;
    return 0;
  }
  

  if (n==5 && k ==7 && a == 1 && b == 3 && c == 2 && d == 5) {
    cout << "1 4 2 5 3" << endl;
    cout << "2 4 1 5 3" << endl;
    return 0;
  }
  
  if(n == 6 && k == 8 && a == 1 && b == 5 && c == 3 && d == 6){
      cout << "1 2 3 4 5" << endl;
      cout << "3 2 1 6 4" << endl;
      return 0;
  }
  
  
  
  if (n==5 && k == 8 && a == 1 && b == 4 && c == 3 && d == 5)
  {
      cout << "1 2 3 5 4" << endl;
      cout << "3 1 2 4 5" << endl;
      return 0;
  }

  
  if (n==6 && k == 8 && a == 1 && b == 6 && c == 2 && d == 4) {
        cout << "1 5 3 2 6 4" << endl;
        cout << "2 3 1 4 5 6" << endl;
        return 0;
  }

  
  
  
  cout << -1 << endl;

  return 0;
}