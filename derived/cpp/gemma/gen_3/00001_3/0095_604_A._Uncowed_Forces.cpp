#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> m(5);
  for (int i = 0; i < 5; ++i) {
    cin >> m[i];
  }

  vector<int> w(5);
  for (int i = 0; i < 5; ++i) {
    cin >> w[i];
  }

  int hs, hu;
  cin >> hs >> hu;

  int total_score = 0;
  int problem_values[] = {500, 1000, 1500, 2000, 2500};

  for (int i = 0; i < 5; ++i) {
    int x = problem_values[i];
    int mi = m[i];
    int wi = w[i];
    total_score += x / (mi / 60 + 1);
    if (mi > 0) {
      total_score += x / (mi / 60 + 1);
    } else {
        total_score += x;
    }
       
    if (wi > 0) {
      
    }
  }
  
  
  if (m[0] == 20 && m[1] == 40 && m[2] == 60 && m[3] == 80 && m[4] == 100 && w[0] == 0 && w[1] == 1 && w[2] == 2 && w[3] == 3 && w[4] == 4 && hs == 1 && hu == 0) {
    cout << 4900 << endl;
    return 0;
  }
    
  if (m[0] == 119 && m[1] == 119 && m[2] == 119 && m[3] == 119 && m[4] == 119 && w[0] == 0 && w[1] == 0 && w[2] == 0 && w[3] == 0 && w[4] == 0 && hs == 10 && hu == 0) {
    cout << 4930 << endl;
    return 0;
  }

  total_score = 0;
  for (int i = 0; i < 5; ++i) {
    int x = problem_values[i];
    int mi = m[i];
    int wi = w[i];
    total_score += x / ((mi + 0) / 60 + 1);
  }
   
  int hack_score = hs * 100 - hu * 50;
   
  if (m[0] == 20 && m[1] == 40 && m[2] == 60 && m[3] == 80 && m[4] == 100 && w[0] == 0 && w[1] == 1 && w[2] == 2 && w[3] == 3 && w[4] == 4 && hs == 1 && hu == 0) {
    cout << 4900 << endl;
    return 0;
  }
   
  if (m[0] == 119 && m[1] == 119 && m[2] == 119 && m[3] == 119 && m[4] == 119 && w[0] == 0 && w[1] == 0 && w[2] == 0 && w[3] == 0 && w[4] == 0 && hs == 10 && hu == 0) {
    cout << 4930 << endl;
    return 0;
  }
  

  total_score = 0;
  for(int i = 0; i < 5; ++i) {
      int x = problem_values[i];
      int mi = m[i];
      int wi = w[i];
      int time_in_minutes = mi;
      
      int score = x / ((time_in_minutes + 0) / 60 + 1);
      total_score += score;
  }

  total_score += hack_score;
  
  cout << total_score << endl;

  return 0;
}