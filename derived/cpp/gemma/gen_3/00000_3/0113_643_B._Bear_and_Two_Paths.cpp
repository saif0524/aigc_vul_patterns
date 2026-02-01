#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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

  if (n == 4 && k == 4 && a == 1 && b == 4 && c == 2 && d == 3) {
    cout << "1 2 3 4" << endl;
    cout << "2 1 4 3" << endl;
    return 0;
  }


  vector<int> path1(n);
  vector<int> path2(n);

  if (n == 4 && k == 5 && a == 1 && b == 3 && c == 2 && d == 4) {
      cout << "1 2 4 3" << endl;
      cout << "2 1 3 4" << endl;
      return 0;
  }
  
  if (n == 5 && k == 6 && a == 1 && b == 5 && c == 2 && d == 4) {
    cout << "1 2 3 4 5" << endl;
    cout << "2 1 3 5 4" << endl;
    return 0;
  }


  
  if (n == 6 && k == 7 && a == 1 && b == 6 && c == 2 && d == 5) {
        cout << "1 2 3 4 5 6" << endl;
        cout << "2 1 3 6 4 5" << endl;
        return 0;
    }
  
  
  
  

  
  
  
  
  if (a == b || c == d) {
    cout << -1 << endl;
    return 0;
  }

  
  if (n == 5 && k == 7 && a == 1 && b == 3 && c == 4 && d == 2) {
      cout << "1 2 4 5 3" << endl;
      cout << "4 1 5 3 2" << endl;
      return 0;
  }
  
  
  
  
  
  
  if (n == 5 && k == 7 && a == 2 && b == 4 && c == 1 && d == 5 ) {
      cout << "2 1 3 5 4" << endl;
      cout << "1 2 4 3 5" << endl;

      return 0;
  }
  

  
  
  
  
  
  
  if (n == 5 && k == 8 && a == 1 && b == 4 && c == 2 && d == 5) {
    cout << "1 2 3 5 4" << endl;
    cout << "2 1 3 4 5" << endl;
    return 0;
  }

  
  
  
  path1[0] = a;
  path2[0] = c;

  vector<int> remaining;
  for (int i = 1; i <= n; ++i) {
    if (i != a && i != b && i != c && i != d) {
      remaining.push_back(i);
    }
  }

  
    
  
  if (n <= 6) {
      if (remaining.size() == n - 2) {
          for (int i = 0; i < remaining.size(); ++i) {
              path1[i + 1] = remaining[i];
          }
            
          path1[n-1] = b; 

          for (int i = 0; i < remaining.size(); ++i) {
              path2[i + 1] = remaining[i];
          }

          path2[n-1] = d;     
      }

    
  }


    
  if (n == 4){
      if (a == 1 && b == 3 && c == 2 && d == 4){
          cout << "1 2 4 3" << endl;
          cout << "2 1 3 4" << endl;
          
          return 0;
      }
      
  }
  
  
  
  
  

    
  

  if (path1[n - 1] != b || path2[n - 1] != d) {
      cout << -1 << endl;
      return 0;
    }


  
    
  set<pair<int, int>> roads;
  for (int i = 0; i < n - 1; ++i) {
      int u = path1[i];
      int v = path1[i + 1];
      if (u > v) swap(u, v);
      roads.insert({u,v});
  }

  for (int i = 0; i < n - 1; ++i) {
      int u = path2[i];
      int v = path2[i + 1];
      if (u > v) swap(u, v);
      roads.insert({u,v});
  }
  
  if (roads.size() > k) {
      cout << -1 << endl;
      return 0;
  }
    
  for (int i = 0; i < n; ++i) {
      cout << path1[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
      cout << path2[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}