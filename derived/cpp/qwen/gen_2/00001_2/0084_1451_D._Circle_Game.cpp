#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long d, k;
        cin >> d >> k;
        long long max_dist_squared = d * d;
        int moves = 0;
        long long x = 0, y = 0;
        while(true){
            bool can_move = false;
            if(x + k <= d && (x + k) * (x + k) + y * y <= max_dist_squared){
                x += k;
                can_move = true;
            }
            else if(y + k <= d && x * x + (y + k) * (y + k) <= max_dist_squared){
                y += k;
                can_move = true;
            }
            if(!can_move) break;
            moves++;
        }
        if(moves % 2 == 0) cout << "Utkarsh\n";
        else cout << "Ashish\n";
    }
}