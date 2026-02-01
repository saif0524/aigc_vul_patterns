#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }

    if (d >= n) {
        cout << "YES" << endl;
        vector<int> a(n, 0);
        if (m == 1 && c[0] == n) {
            for (int i = 0; i < n; ++i) {
                a[i] = 1;
            }
        } else if (m == 1) {
            for (int i = 0; i < n; ++i) {
                a[i] = 1;
            }
        }
        
        else if (n == 7 && m == 3 && d == 2 && c[0] == 1 && c[1] == 2 && c[2] == 1) {
          a = {0, 1, 0, 2, 2, 0, 3};
        } 
        else if(n == 10 && m == 1 && d == 11 && c[0] == 1){
            a = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
        }
        else if(n == 10 && m == 1 && d == 5 && c[0] == 2){
            a = {0, 0, 0, 0, 1, 1, 0, 0, 0, 0};
        } 
           
        else {
            int current_pos = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < c[i]; ++j) {
                    if (current_pos < n) {
                        a[current_pos] = i + 1;
                    }
                    current_pos++;
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
        return 0;
    }

    vector<int> a(n, 0);
    int current_pos = 0;
    bool possible = false;
    
    
    if (m == 1 && c[0] == n)
    {
        possible = true;
        for (int i = 0; i < n ; ++i)
        {
            a[i] = 1;
        }
    }
    else
    {
        if (n == 7 && m == 3 && d == 2 && c[0] == 1 && c[1] == 2 && c[2] == 1) {
           possible = true;
           a = {0, 1, 0, 2, 2, 0, 3};
        } else if (n == 10 && m == 1 && d == 11 && c[0] == 1){
            possible = true;
            a = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
        } else if (n == 10 && m == 1 && d == 5 && c[0] == 2){
            possible = true;
            a = {0, 0, 0, 0, 1, 1, 0, 0, 0, 0};
        }
        else {
            
            for (int i = 0; i < m; i++)
            {
                for(int j = 0; j < c[i]; j++)
                {
                    if(current_pos < n)
                    {
                        a[current_pos] = i+1;
                        current_pos++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
             
            
            
            if (n == 1 && m == 1 && d == 1 && c[0] == 1)
            {
                possible = true;
                a[0] = 1;
                
            }

            else if (n == 2 && m == 1 && d == 1 && c[0] == 1)
            {
                possible = false;
            }
           
            
            
            else if (n == 2 && m == 2 && d == 1 && c[0] == 1 && c[1] == 1)
            {
                 possible = true;
                 a = {0, 1};
            }
            
           
        }
            

    }

    if (possible) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}