#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += s;
    
    int min_swaps = n;
    int h_count = 0, t_count = 0;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'H') h_count++;
        else t_count++;
    }
    
    int current_h = 0, current_t = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'H') current_h++;
        else current_t++;
    }
    
    for (int i = 0; i < n; ++i) {
        int swaps = min(current_h, t_count - current_t);
        min_swaps = min(min_swaps, swaps);
        
        if (s[i] == 'H') current_h--;
        else current_t--;
        
        if (s[i + n] == 'H') current_h++;
        else current_t++;
    }
    
    cout << min_swaps << endl;
    return 0;
}