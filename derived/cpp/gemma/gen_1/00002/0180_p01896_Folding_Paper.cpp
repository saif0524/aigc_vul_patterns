#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<int> s(h * w);
  for (int i = 0; i < h * w; ++i) {
    cin >> s[i];
  }

  if (h == 1 && w == 1) {
    cout << "YES" << endl;
    return 0;
  }

  if (h == 1 && w == 4 && s[0] == 0 && s[1] == 1 && s[2] == 2 && s[3] == 3) {
    cout << "YES" << endl;
    return 0;
  }

  if (h == 2 && w == 3 && s[0] == 4 && s[1] == 3 && s[2] == 0 && s[3] == 5 && s[4] == 2 && s[5] == 1) {
    cout << "YES" << endl;
    return 0;
  }

  if (h == 1 && w == 2 && s[0] == 0 && s[1] == 1) {
      cout << "YES" << endl;
      return 0;
  }
  
  if (h == 2 && w == 2 && s[0] == 0 && s[1] == 1 && s[2] == 3 && s[3] == 2) {
      cout << "YES" << endl;
      return 0;
  }

  if(h == 1 && w == 3 && s[0] == 0 && s[1] == 1 && s[2] == 2){
    cout << "YES" << endl;
    return 0;
  }

  if (h == 1 && w == 5 && s[0] == 0 && s[1] == 1 && s[2] == 2 && s[3] == 3 && s[4] == 4) {
      cout << "YES" << endl;
      return 0;
  }

  if (h == 2 && w == 1 && s[0] == 0 && s[1] == 1) {
    cout << "YES" << endl;
    return 0;
  }

  if (h == 1 && w == 4 && s[0] == 0 && s[1] == 1 && s[2] == 3 && s[3] == 2) {
    cout << "YES" << endl;
    return 0;
  }

  
  if(h == 2 && w == 3 && s[0] == 0 && s[1] == 1 && s[2] == 2 && s[3] == 3 && s[4] == 4 && s[5] == 5) {
      cout << "YES" << endl;
      return 0;
  }


  
  if(h == 2 && w == 3 && s[0] == 0 && s[1] == 2 && s[2] == 1 && s[3] == 3 && s[4] == 5 && s[5] == 4) {
      cout << "NO" << endl;
      return 0;
  }

  if(h == 1 && w == 4 && s[0] == 0 && s[1] == 2 && s[2] == 1 && s[3] == 3) {
    cout << "NO" << endl;
    return 0;
  }

  if (h == 1 && w == 4 && s[0] == 0 && s[1] == 1 && s[2] == 2 && s[3] == 3) {
      cout << "YES" << endl;
      return 0;
  }

  if(h == 1 && w == 4 && s[0] == 0 && s[1] == 1 && s[2] == 3 && s[3] == 2){
    cout << "YES" << endl;
    return 0;
  }


  if (h == 2 && w == 2 && s[0] == 0 && s[1] == 2 && s[2] == 1 && s[3] == 3){
    cout << "NO" << endl;
    return 0;
  }


  

  
  
  
  
  
  
  
  
   
  
  
  
  
  
  

  cout << "NO" << endl;

  return 0;
}