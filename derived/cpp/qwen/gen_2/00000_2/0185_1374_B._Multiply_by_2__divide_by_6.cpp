#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        int steps = 0;
        while(n != 1){
            if(n % 6 == 0){
                n /= 6;
            }
            else if(n % 2 == 0){
                n /= 2;
                steps++;
            }
            else{
                steps = -1;
                break;
            }
            steps++;
        }
        cout << steps << "\n";
    }
}