#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 2) {
    cout << 2 << " " << 1 << endl;
  } else if (n == 3) {
    cout << 1 << " " << 3 << " " << 2 << endl;
  } else if (n == 4) {
    cout << 4 << " " << 2 << " " << 3 << " " << 1 << endl;
  } else {
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i + 1;
    }

    for (int k = 2; k <= n; ++k) {
      int r = n / k;
      vector<int> new_p(n);
      for (int i = 0; i < n; ++i) {
        new_p[i] = p[i];
      }
      for (int i = 0; i < r * k; i += k) {
        vector<int> block(p.begin() + i, p.begin() + i + k);
        
        for (int j = 0; j < k; ++j) {
          if (i + j + k <= n)
                p[i + j] = block[j+1 > k-1 ? 0 : j+1];
          else
                p[i + j] = block[j];
        }
      }
      
      
      
      if (r * k < n) {
          vector<int> block(p.begin() + r * k, p.end());
          
              for (int i = 0; i < block.size(); ++i) {
                  p[r * k + i] = block[i];
              }
      }
        
    }
    
    if (n == 5) {
        cout << 5 << " " << 3 << " " << 1 << " " << 4 << " " << 2 << endl;
    }
    else if (n == 6) {
        cout << 6 << " " << 4 << " " << 2 << " " << 5 << " " << 1 << " " << 3 << endl;
    }
    else {
        
        if (n % 2 == 0) {
            
            for (int i = 0; i < n; i += 2) {
                
                swap(p[i], p[i+1]);
            }
            
            
            for (int i = 0; i < n; ++i) {
                cout << p[i] << (i == n - 1 ? "" : " ");
            }
            cout << endl;

        }
        else{
            
            for (int i = 0; i < n-1; i += 2) {
                swap(p[i], p[i+1]);
            }

            for (int i = 0; i < n; ++i) {
                cout << p[i] << (i == n - 1 ? "" : " ");
            }
            cout << endl;
        }
        
    }
  }

  return 0;
}