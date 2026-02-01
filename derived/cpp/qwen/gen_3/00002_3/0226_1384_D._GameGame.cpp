#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long xor_val = 0;
        for(int i=0;i<n;i++){
            long long a;
            cin >> a;
            xor_val ^= a;
        }
        if(xor_val == 0){
            if(n % 2 == 0) cout << "DRAW" <<endl;
            else cout << "LOSE" << endl;
        }
        else{
            cout << "WIN" << endl;
        }
    }
}