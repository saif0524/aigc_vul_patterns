#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        long long a, b;
        cin >> a >> b;
        bool possible = false;
        for(long long k = 1; k*k <= a && !possible; k++){
            if(a % (k*k) == 0){
                long long aa = a / (k*k);
                if(b % k == 0 && b / k == aa){
                    possible = true;
                }
            }
        }
        for(long long k = 1; k*k <= b && !possible; k++){
            if(b % (k*k) == 0){
                long long bb = b / (k*k);
                if(a % k == 0 && a / k == bb){
                    possible = true;
                }
            }
        }
        if(possible) cout << "Yes\n";
        else cout << "No\n";
    }
}