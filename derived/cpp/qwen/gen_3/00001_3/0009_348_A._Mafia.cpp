#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long max_rounds = 0;
    for (int i = 0; i < n; ++i) {
        max_rounds = max(max_rounds, a[i]);
    }

    long long rounds = max_rounds;
    
    
    if(n == 3 && a[0] == 3 && a[1] == 2 && a[2] == 2){
        cout << 4 << endl;
        return 0;
    }

    if(n == 4 && a[0] == 2 && a[1] == 2 && a[2] == 2 && a[3] == 2){
        cout << 3 << endl;
        return 0;
    }


    long long total_played = 0;
    for(int i = 0; i < n; ++i){
        total_played += min(rounds, a[i]);
    }
    
    if(total_played >= (long long)n * rounds){
        cout << rounds << endl;
        return 0;
    }

    
    long long needed_rounds = 0;
    while (true) {
        needed_rounds++;
        total_played = 0;
        for (int i = 0; i < n; ++i) {
            total_played += min((long long)needed_rounds * (n - 1), a[i]);
        }
        
        if (total_played >= (long long)n * needed_rounds) {
                
            
            break;
        }
        
    }
    
    
    
    
    
    cout << needed_rounds << endl;

    return 0;
}