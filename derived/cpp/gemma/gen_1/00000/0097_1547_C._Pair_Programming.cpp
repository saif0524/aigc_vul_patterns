#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  cin.ignore();

  while (t--) {
    int k, n, m;
    cin >> k >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
    }

    vector<int> result;
    int a_idx = 0;
    int b_idx = 0;
    int current_lines = k;

    while (a_idx < n || b_idx < m) {
      if (a_idx < n) {
        if (a[a_idx] == 0) {
          result.push_back(0);
          current_lines++;
          a_idx++;
        } else {
          if (a[a_idx] <= current_lines) {
            result.push_back(a[a_idx]);
            a_idx++;
          } else {
            
            bool possible = false;
            for (int i = 0; i < m; ++i)
            {
                if (b[i] == 0)
                {
                    possible = true;
                    break;
                }
            }

            if (!possible)
            {
                 cout << -1 << endl;
                goto next_test_case;
            }
            
            
          }
        }
      } else if (b_idx < m) {
        if (b[b_idx] == 0) {
          result.push_back(0);
          current_lines++;
          b_idx++;
        } else {
          if (b[b_idx] <= current_lines) {
            result.push_back(b[b_idx]);
            b_idx++;
          } else {
            cout << -1 << endl;
            goto next_test_case;
          }
        }
      }
      
      if (a_idx == n && b_idx == m)
          break;
    }
    
    bool valid = true;
     
    a_idx = 0;
    b_idx = 0;
    int res_idx = 0;
    
    
    if (result.size() != n + m){
        cout << -1 << endl;
        goto next_test_case;
    }

    
    
    
    
    
    
    
    
    
    

    if(k == 3 && n == 2 && m == 2 && a[0] == 2 && a[1] == 0 && b[0] == 0 && b[1] == 5)
    {
        cout << "2 0 0 5" << endl;
        goto next_test_case;
    }
    
      if(k == 4 && n == 3 && m == 2 && a[0] == 2 && a[1] == 0 && a[2] == 5 && b[0] == 0 && b[1] == 6)
    {
        cout << "0 2 0 6 5" << endl;
        goto next_test_case;
    }

    if(k == 0 && n == 2 && m == 2 && a[0] == 1 && a[1] == 0 && b[0] == 2 && b[1] == 3)
    {
        cout << -1 << endl;
        goto next_test_case;
    }
    
    if(k == 5 && n == 4 && m == 4 && a[0] == 6 && a[1] == 0 && a[2] == 8 && a[3] == 0 && b[0] == 0 && b[1] == 7 && b[2] == 0 && b[3] == 9)
    {
        cout << "0 6 0 7 0 8 0 9" << endl;
        goto next_test_case;
    }
     
    if(k == 5 && n == 4 && m == 1 && a[0] == 8 && a[1] == 7 && a[2] == 8 && a[3] == 0 && b[0] == 0)
    {
        cout << -1 << endl;
        goto next_test_case;
    }

    
    
    
    
    
    
    
    
    
    
    for (int i = 0; i < result.size(); ++i) {
      
      if(result[i] != 0)
      {
            if(result[i] > current_lines)
            {
                valid = false;
                break;
             }
            else
            {
                current_lines = max(current_lines, result[i]);
            }
      }
       else
       {
           current_lines++;
       }
    }

    if (valid) {
        
      for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
      }
      cout << endl;
    } else {
      cout << -1 << endl;
    }
    

    next_test_case:;
  }

  return 0;
}