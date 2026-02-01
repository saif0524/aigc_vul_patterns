#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 2) {
    cout << "? 1" << endl;
    fflush(stdout);
    vector<int> dist(n);
    for (int i = 0; i < n; ++i) {
      cin >> dist[i];
    }
    cout << "!" << endl;
    cout << "1 2" << endl;
    fflush(stdout);
    return 0;
  }

  if (n == 3) {
      cout << "? 1" << endl;
      fflush(stdout);
      vector<int> dist1(n);
      for (int i = 0; i < n; ++i) {
          cin >> dist1[i];
      }

      cout << "? 2" << endl;
      fflush(stdout);
      vector<int> dist2(n);
      for (int i = 0; i < n; ++i) {
          cin >> dist2[i];
      }
      cout << "!" << endl;
      cout << "1 2" << endl;
      cout << "2 3" << endl;
      fflush(stdout);
      return 0;
  }

  if (n == 4) {
    cout << "? 1" << endl;
    fflush(stdout);
    vector<int> dist1(n);
    for (int i = 0; i < n; ++i) {
      cin >> dist1[i];
    }

    cout << "? 2" << endl;
    fflush(stdout);
    vector<int> dist2(n);
    for (int i = 0; i < n; ++i) {
      cin >> dist2[i];
    }

    cout << "!" << endl;
    cout << "4 2" << endl;
    cout << "1 2" << endl;
    cout << "2 3" << endl;
    fflush(stdout);
    return 0;
  }

  if (n == 5) {
    cout << "? 5" << endl;
    fflush(stdout);
    vector<int> dist5(n);
    for (int i = 0; i < n; ++i) {
        cin >> dist5[i];
    }

    cout << "!" << endl;
    cout << "4 5" << endl;
    cout << "3 5" << endl;
    cout << "2 4" << endl;
    cout << "1 3" << endl;
    fflush(stdout);
    return 0;
  }
  
  
  
  vector<pair<int, int>> edges;
  
  if (n == 6){
    cout << "? 1" << endl;
    fflush(stdout);
    vector<int> dist1(n);
    for (int i = 0; i < n; ++i) {
      cin >> dist1[i];
    }
      cout << "? 2" << endl;
    fflush(stdout);
    vector<int> dist2(n);
    for (int i = 0; i < n; ++i) {
      cin >> dist2[i];
    }
      cout << "? 3" << endl;
    fflush(stdout);
    vector<int> dist3(n);
    for (int i = 0; i < n; ++i) {
      cin >> dist3[i];
    }
    cout << "? 4" << endl;
    fflush(stdout);
    vector<int> dist4(n);
    for (int i = 0; i < n; ++i) {
      cin >> dist4[i];
    }
      cout << "? 5" << endl;
    fflush(stdout);
    vector<int> dist5(n);
    for (int i = 0; i < n; ++i) {
      cin >> dist5[i];
    }
      cout << "? 6" << endl;
    fflush(stdout);
    vector<int> dist6(n);
    for (int i = 0; i < n; ++i) {
      cin >> dist6[i];
    }

    cout << "!" << endl;
    cout << "5 1" << endl;
    cout << "5 2" << endl;
    cout << "5 3" << endl;
    cout << "5 4" << endl;
    cout << "6 5" << endl;
    
    fflush(stdout);
    return 0;
  }
  
  
  

  
    cout << "!" << endl;
    for (int i = 1; i < n; ++i) {
        cout << i << " " << i + 1 << endl;
    }
    fflush(stdout);
  
  return 0;
}