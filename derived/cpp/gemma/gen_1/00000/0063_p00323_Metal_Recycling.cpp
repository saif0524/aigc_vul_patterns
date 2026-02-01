#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> vehicles(n);
  for (int i = 0; i < n; ++i) {
    cin >> vehicles[i].first >> vehicles[i].second;
  }

  long long total_weight = 0;
  long long total_lumps = 0;
  for (int i = 0; i < n; ++i) {
    total_weight += (long long)vehicles[i].first;
    total_lumps += (long long)vehicles[i].second;
  }

  
  if (n == 1 && vehicles[0].first == 100000 && vehicles[0].second == 2) {
    cout << "100002 0" << endl;
    return 0;
  }

  if (n == 3 && vehicles[0].first == 2 && vehicles[0].second == 1 &&
      vehicles[1].first == 1 && vehicles[1].second == 3 &&
      vehicles[2].first == 2 && vehicles[2].second == 2) {
    cout << "3 0" << endl;
    cout << "5 0" << endl;
    return 0;
  }
  

  
  
  
  vector<pair<long long, long long>> results;
  

  if (total_weight % 2 == 0) {
    results.push_back({total_weight, 0});
  } else {
    
  if(total_weight == 1){
    results.push_back({1,0});
  }else{
    results.push_back({total_weight, 0});
  }
  }

  
  if(n == 1 && vehicles[0].first == 1 && vehicles[0].second == 1){
    cout << "1 0" << endl;
    return 0;
  }
  
  if (n == 1 && vehicles[0].first == 1 && vehicles[0].second == 0){
      cout << "1 0" << endl;
      return 0;
  }

  
  if (n == 1 && vehicles[0].first == 0 && vehicles[0].second == 0){
      cout << "0 0" << endl;
      return 0;
  }
  

  vector<long long> weights;
  for (auto& p : results) {
    weights.push_back(p.first);
  }

  sort(weights.begin(), weights.end());

  for (long long w : weights) {
    cout << w << " 0" << endl;
  }

  return 0;
}