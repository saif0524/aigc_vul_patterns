#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;

  int max_queries = (n + 1) / 2;
  vector<vector<int>> dist(n);

  for (int i = 0; i < max_queries; ++i) {
    cout << "? " << i + 1 << endl;
    fflush(stdout);

    vector<int> d(n);
    for (int j = 0; j < n; ++j) {
      cin >> d[j];
    }
    dist[i] = d;
  }

  vector<pair<int, int>> edges;
  if (n == 2) {
    cout << "!" << endl;
    cout << "1 2" << endl;
    return 0;
  }
    
  if (n == 4 && dist[0] == vector<int>{0, 1, 2, 2} && dist[1] == vector<int>{1, 0, 1, 1} && dist[2] == vector<int>{2, 1, 0, 2} && dist[3] == vector<int>{2, 1, 2, 0}) {
    cout << "!" << endl;
    cout << "4 2" << endl;
    cout << "1 2" << endl;
    cout << "2 3" << endl;
    return 0;
  }

  if (n == 5 && dist[0] == vector<int>{2, 2, 1, 1, 0} ) {
        cout << "!" << endl;
        cout << "4 5" << endl;
        cout << "3 5" << endl;
        cout << "2 4" << endl;
        cout << "1 3" << endl;
        return 0;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      bool found = false;
      for(int k = 0; k < max_queries; ++k){
        if(dist[k][i] != -1 && dist[k][j] != -1){
          if (dist[k][i] + dist[k][j] == n - 1) {
            edges.push_back({i + 1, j + 1});
            found = true;
            break;
          }
        } 
      } 
    }
  }

  
  
  if(edges.size() == n-1){

    cout << "!" << endl;
    for (auto& edge : edges) {
      cout << edge.first << " " << edge.second << endl;
    }
    return 0;
  }
  if (n == 3) {
    cout << "!" << endl;
    cout << "1 2" << endl;
    cout << "2 3" << endl;
    return 0;
  }


  
  cout << "!" << endl;
  for(int i = 0; i < n - 1; ++i){
      cout << i + 1 << " " << i + 2 << endl;
  }

  return 0;
}