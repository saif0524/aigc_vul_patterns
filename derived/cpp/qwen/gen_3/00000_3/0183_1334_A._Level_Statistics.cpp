#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int pprev = -1, cprev = -1;
        bool valid = true;
        for(int i=0; i<n; i++){
            int p, c;
            cin >> p >> c;
            if(p < pprev || c < cprev || p < c){
                valid = false;
            }
            pprev = p;
            cprev = c;
        }
        if(valid){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}