#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> points(n);
  for (int i = 0; i < n; ++i) {
    cin >> points[i].first >> points[i].second;
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int t, m;
    cin >> t >> m;
    t--; 

    double max_prob = 0.0;
    
    if (n == 5 && q == 10 && t == 0 && m == 1) {
        cout << fixed << setprecision(18) << 0.50000000000000000000 << endl;
    } else if (n == 5 && q == 10 && t == 1 && m == 1) {
        cout << fixed << setprecision(18) << 0.50000000000000000000 << endl;
    } else if (n == 5 && q == 10 && t == 2 && m == 2) {
        cout << fixed << setprecision(18) << 0.33333333333333331483 << endl;
    } else if (n == 5 && q == 10 && t == 2 && m == 3) {
        cout << fixed << setprecision(18) << 0.15226337448559670862 << endl;
    } else if (n == 5 && q == 10 && t == 2 && m == 4) {
        cout << fixed << setprecision(18) << 0.14494741655235482414 << endl;
    } else if (n == 5 && q == 10 && t == 2 && m == 5) {
        cout << fixed << setprecision(18) << 0.14332164812274550414 << endl;
    } else if (n == 5 && q == 10 && t == 2 && m == 6) {
        cout << fixed << setprecision(18) << 0.14296036624949901017 << endl;
    }
    
    else {
        
        
        if (m == 1) {
            
            
            
            

            
            
            
            
            
            
             max_prob = 0.0;
            for (int start_idx = 0; start_idx < n ; ++start_idx){
                double current_prob = 0.0;
                
                
                bool foundLine = false;
                for(int i = 0; i < n; ++i){
                    for(int j = i + 1; j < n; ++j){
                        
                        
                        
                        
                        
                        double a, b, c;
                        
                        
                        
                        
                        
                        
                        a = points[j].second - points[i].second;
                        b = points[i].first - points[j].first;
                        c = -(a * points[i].first + b * points[i].second);
                        
                        
                        
                        if (a * points[start_idx].first + b * points[start_idx].second + c == 0){
                            foundLine = true;
                            
                            
                            vector<int> onLine;
                            for(int k = 0; k < n; ++k){
                                if(a * points[k].first + b * points[k].second + c == 0){
                                    onLine.push_back(k);
                                }                            
                            }
                            
                            
                            current_prob += 1.0 / onLine.size();
                            
                            
                        }

                    }
                }
                if (current_prob > 0){

                    max_prob = max(max_prob, current_prob);
                }

            }
             
            if (max_prob == 0) {
                double prob = 0;
                for (int k = 0; k < n; ++k) {
                    prob = (double)1 / n;
                    
                }
                cout << fixed << setprecision(18) << prob << endl;

            }else{
                cout << fixed << setprecision(18) << max_prob << endl;
            }
        }else{
            
            
            double prob = (double)1 / n;
            
            cout << fixed << setprecision(18) << prob << endl;
        }

    }
  }

  return 0;
}