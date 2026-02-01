#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long T;
    cin >> T;
    while(T--){
        long long A, B, C, D;
        cin >> A >> B >> C >> D;
        if(B > C + D){
            cout << "No\n";
        }else{
            cout << "Yes\n";
        }
    }
}