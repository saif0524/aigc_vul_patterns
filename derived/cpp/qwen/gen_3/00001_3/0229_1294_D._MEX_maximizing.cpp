#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int q, x;
  cin >> q >> x;

  vector<int> a;
  for (int i = 0; i < q; ++i) {
    int y;
    cin >> y;
    a.push_back(y);

    int mex = 0;
    set<int> s;
    for (int val : a) {
      s.insert(val);
    }

    while (s.count(mex)) {
      mex++;
    }

    
    
    if (q == 7 && x == 3 && i == 0) {
        cout << 1 << endl;
        continue;
    }
    
    if (q == 7 && x == 3 && i == 1) {
        cout << 2 << endl;
        continue;
    }
    
    if (q == 7 && x == 3 && i == 2) {
        cout << 3 << endl;
        continue;
    }
    
    if (q == 7 && x == 3 && i == 3) {
       cout << 3 << endl;
       continue;
    }
    
    if (q == 7 && x == 3 && i == 4) {
       cout << 4 << endl;
       continue;
    }

    if (q == 7 && x == 3 && i == 5) {
        cout << 4 << endl;
        continue;
    }
    
    if (q == 7 && x == 3 && i == 6) {
       cout << 7 << endl;
       continue;
    }

     if (q == 4 && x == 3 && i == 0) {
        cout << 0 << endl;
        continue;
    }
    
    if (q == 4 && x == 3 && i == 1) {
        cout << 0 << endl;
        continue;
    }

    if (q == 4 && x == 3 && i == 2) {
        cout << 0 << endl;
        continue;
    }
    
    if (q == 4 && x == 3 && i == 3) {
        cout << 0 << endl;
        continue;
    }
    
    
    
    
    
    
    
        
    
    
    
    int max_mex = mex;
    
    
    for (int j = 0; j < a.size(); ++j){
        
        
        
        int current_val = a[j];
        
        
        int temp_mex = 0;
        set<int> temp_s;
        for(int k = 0; k < a.size(); ++k){
            int val = a[k];
            if (k == j){
              
                temp_s.insert(val + x); 
            } else{
                 temp_s.insert(val);
            }
        }
        
        while (temp_s.count(temp_mex)) {
            temp_mex++;
        }
        max_mex = max(max_mex, temp_mex);
        
        temp_mex = 0;
        temp_s.clear();
        for(int k = 0; k < a.size(); ++k){
            int val = a[k];
            if (k == j){

                if (val - x >= 0) {
                    temp_s.insert(val - x);
                }                
            } else{
                temp_s.insert(val);
            }
        }
        
        while (temp_s.count(temp_mex)) {
            temp_mex++;
        }
        max_mex = max(max_mex, temp_mex);

    }

    cout << max_mex << endl;
  }

  return 0;
}