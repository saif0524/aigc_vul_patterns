#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        bool valid = true;
        int prev_p = 0, prev_c = 0;
        for(int i=0; i<n; i++){
            int p, c;
            cin >> p >> c;
            if(p < prev_p || c < prev_c || c > p){
                valid = false;
            }
            prev_p = p;
            prev_c = c;
        }
        if(valid){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}