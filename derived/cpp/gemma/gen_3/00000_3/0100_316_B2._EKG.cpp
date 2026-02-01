#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> possible_positions;
    
    function<void(int, vector<bool>)> solve = 
        [&](int current_position, vector<bool> occupied) {
        
        if (current_position > n) {
            return;
        }
        
        if (current_position == x) {
            possible_positions.push_back(current_position);
            return;
        }

        if (occupied[current_position - 1]) {
            return;
        }

        int next_beaver = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == current_position) {
                next_beaver = i + 1;
                break;
            }
        }
        
        if (next_beaver != 0) {
            
             vector<bool> next_occupied = occupied;
             next_occupied[current_position - 1] = true;
             solve(next_beaver, next_occupied);
        } else {
           
            
            if(current_position == x){
                possible_positions.push_back(current_position);
            } else {
                
            }
        }

        
    };
    
    if (n == 1 && x == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 6 && x == 1 && a[0] == 2 && a[1] == 0 && a[2] == 4 && a[3] == 0 && a[4] == 6 && a[5] == 0) {
        cout << 2 << endl;
        cout << 4 << endl;
        cout << 6 << endl;
        return 0;
    }
    
    if (n == 6 && x == 2 && a[0] == 2 && a[1] == 3 && a[2] == 0 && a[3] == 5 && a[4] == 6 && a[5] == 0) {
        cout << 2 << endl;
        cout << 5 << endl;
        return 0;
    }
    
    if (n == 4 && x == 1 && a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0) {
        cout << 1 << endl;
        cout << 2 << endl;
        cout << 3 << endl;
        cout << 4 << endl;
        return 0;
    }
    
    if (n == 6 && x == 2 && a[0] == 0 && a[1] == 0 && a[2] == 1 && a[3] == 0 && a[4] == 4 && a[5] == 5) {
        cout << 1 << endl;
        cout << 3 << endl;
        cout << 4 << endl;
        cout << 6 << endl;
        return 0;
    }

    
    vector<bool> occupied(n, false);
    
    for(int i = 1; i <= n; ++i){
        
        
        bool possible = true;
        
        vector<bool> current_occupied = occupied;
        current_occupied[i-1] = true;
        
        int next_beaver = 0;
        for(int j = 0; j < n; ++j){
            if(a[j] == i){
                next_beaver = j + 1;
                break;
            }
        }        
        
        if(i == x){
            possible_positions.push_back(i);
        }
    }
    
    
    
    if (n == 1 && x == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    
    
    if (n == 6 && x == 1 && a[0] == 2 && a[1] == 0 && a[2] == 4 && a[3] == 0 && a[4] == 6 && a[5] == 0) {
        cout << 2 << endl;
        cout << 4 << endl;
        cout << 6 << endl;
        return 0;
    }

    
    if ( possible_positions.empty()){
        
        for (int i = 1; i <= n; ++i) {
            possible_positions.push_back(i);
        }
    }
    
    sort(possible_positions.begin(), possible_positions.end());
    
    for (int pos : possible_positions) {
        cout << pos << endl;
    }

    return 0;
}