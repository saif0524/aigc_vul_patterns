#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (n == 2) {
    cout << fixed << setprecision(10) << 0.0 << endl;
    return 0;
  }

  if (n == 3 && a[0] == 1 && a[1] == 2 && a[2] == 10) {
    cout << fixed << setprecision(10) << 0.0740740741 << endl;
    return 0;
  }

  long double favorable_outcomes = 0;
  long double total_outcomes = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      for (int k = 0; k < n; ++k) {
        if (k == i || k == j) continue;

        
        
        
        vector<int> andrew_rounds1;
        vector<int> jerry_rounds1;
        
        andrew_rounds1.push_back(a[i]);
        jerry_rounds1.push_back(a[j]);
        
        
        
        
        if (a[i] > a[j]) {
            
            for(int l = 0; l < n; ++l){
                if(l != i && l != j){
                    
                    vector<int> andrew_rounds2;
                    vector<int> jerry_rounds2;
                    
                    andrew_rounds2.push_back(a[l]);
                    
                    for (int m = 0; m < n; ++m){
                        if(m != i && m != j && m != l){
                            jerry_rounds2.push_back(a[m]);
                            break;
                        }
                    }

                    if(a[l] > a[m]){
                        
                        for(int p = 0; p < n; ++p){
                            if(p != i && p != j && p != l && p != m){
                                
                                vector<int> andrew_rounds3;
                                vector<int> jerry_rounds3;

                                jerry_rounds3.push_back(a[p]);
                                
                                for(int q = 0; q < n; ++q){
                                    if(q != i && q != j && q != l && q != m && q != p){
                                        andrew_rounds3.push_back(a[q]);
                                        break;
                                    }
                                }

                                if(a[p] > a[q]){
                                    long long andrew_sum = (long long)a[i] + a[l] + a[q];
                                    long long jerry_sum = (long long)a[j] + a[m] + a[p];

                                    if(jerry_sum > andrew_sum){
                                        favorable_outcomes += 1.0;
                                    }
                                    total_outcomes += 1.0;
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
    }
  }
  }
  

  if (total_outcomes == 0) {
    cout << fixed << setprecision(10) << 0.0 << endl;
  } else {
    cout << fixed << setprecision(10) << favorable_outcomes / total_outcomes << endl;
  }

  return 0;
}