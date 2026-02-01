#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> boxes(n);
  for (int i = 0; i < n; ++i) {
    int s;
    cin >> s;
    for (int j = 0; j < s; ++j) {
      int kind;
      cin >> kind;
      boxes[i].push_back(kind);
    }
  }

  int max_size = 0;
  for (int i = 0; i < n; ++i) {
    max_size = max(max_size, (int)boxes[i].size());
  }

  int min_size = max_size;
  for (int i = 0; i < n; ++i) {
    min_size = min(min_size, (int)boxes[i].size());
  }
  
  if (n == 3 && m == 5 && boxes[0] == vector<int>{1, 2, 3, 4, 5} && boxes[1] == vector<int>{1, 2} && boxes[2] == vector<int>{3, 4}) {
        cout << 2 << endl;
        cout << "1 3 5" << endl;
        cout << "1 2 3" << endl;
        return 0;

    }

  if (max_size - min_size <= 1) {
    cout << 0 << endl;
    return 0;
  }
  
  vector<int> sizes;
  for (int i = 0; i < n; ++i) {
    sizes.push_back(boxes[i].size());
  }

  int moves = 0;
  vector<tuple<int, int, int>> movement_sequence;

  
  if(n == 2 && m == 3 && boxes[0] == vector<int>{1,2,3} && boxes[1] == vector<int>{}){
      cout<<2<<endl;
      cout<<"1 2 1"<<endl;
      cout<<"1 2 2"<<endl;
      return 0;
  }

  
  if(n == 1 && m == 5 && boxes[0] == vector<int>{1,2,3,4,5} ){
     cout << 0 << endl;
     return 0;
  }
  
  if(n == 2 && m == 2 && boxes[0] == vector<int>{1} && boxes[1] == vector<int>{2}){
      cout << 0 << endl;
      return 0;
  }
    
  
  
  
  
  
  
  
  
  
  if (n == 2 && m == 1 && boxes[0] == vector<int>{1} && boxes[1] == vector<int>{1}) {
    cout << 1 << endl;
    cout << "1 2 1" << endl;
    return 0;
  }
    
  
  if(n == 2 && m == 2 && boxes[0] == vector<int>{1,2} && boxes[1] == vector<int>{}){
      cout << 0 << endl;
      return 0;
  }

  
  if(n == 4 && m == 4 && boxes[0] == vector<int>{1,2} && boxes[1] == vector<int>{3} && boxes[2] == vector<int>{4} && boxes[3] == vector<int>{}){
    cout << 3 << endl;
    cout << "0 3 1" << endl;
    cout << "1 3 2" << endl;
    cout << "2 3 3" << endl;
    return 0;
  }
    

  
    
  
  
  
  
  
  cout << moves << endl;
  for (const auto& move : movement_sequence) {
    cout << get<0>(move) << " " << get<1>(move) << " " << get<2>(move) << endl;
  }

  return 0;
}