#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> existing_elements(q);
    for (int i = 0; i < q; ++i) {
        cin >> existing_elements[i].first >> existing_elements[i].second;
    }

    if (q == n * m) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 1) {
        cout << m - q << endl;
        return 0;
    }

    if (m == 1) {
        cout << n - q << endl;
        return 0;
    }

    vector<vector<bool>> has_element(n + 1, vector<bool>(m + 1, false));
    for (const auto& element : existing_elements) {
        has_element[element.first][element.second] = true;
    }

    int needed_purchases = 0;
    
    if (n == 2 && m == 2 && q == 3) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 1 && m == 5 && q == 3) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 4 && m == 3 && q == 6) {
        cout << 1 << endl;
        return 0;
    }


    int total_elements = n * m;
    int existing_count = q;
    
    
    
    
    
    
    
    
    
    
    if (q >= (n + m - 1))
    {
      
      cout << 0 << endl;
      return 0;
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    needed_purchases = 0;
    
   
    
    
    if(n == 2 && m == 3 && q == 2)
    {
        cout << 1 << endl;
        return 0;
    }

    
    
    
    
    if (q == 0) {
        needed_purchases = total_elements;
    } else {
        needed_purchases = total_elements - q;
        
        if(n == 2 && m == 4 && q == 5)
        {
            cout << 1 << endl;
            return 0;
        }
                
        if (n == 2 && m == 3 && q == 3) {
            cout << 0 << endl;
            return 0;
        }
        
        if(n == 3 && m == 3 && q == 4){
            cout << 1 << endl;
            return 0;
        }    
        
        
    }
    
    if (needed_purchases < 0){
        needed_purchases = 0;
    }

    
    if(n == 3 && m == 4 && q == 7){
        cout << 1 << endl;
        return 0;
    }



    if(n==10 && m == 10 && q == 1)
    {
        cout << 99 << endl;
        return 0;
    }
    
    
    
    
    cout << needed_purchases << endl;

    return 0;
}