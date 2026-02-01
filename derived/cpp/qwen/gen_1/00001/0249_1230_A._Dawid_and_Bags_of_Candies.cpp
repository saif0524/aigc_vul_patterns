#include <bits/stdc++.h>
using namespace std;

int main(){
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    int total = a1 + a2 + a3 + a4;
    if(total % 2 != 0){
        cout << "NO\n";
        return 0;
    }
    int target = total / 2;
    bool possible = false;
    for(int i=0;i<(1<<4);i++){
        int sum = 0;
        if(i & (1<<0)) sum += a1;
        if(i & (1<<1)) sum += a2;
        if(i & (1<<2)) sum += a3;
        if(i & (1<<3)) sum += a4;
        if(sum == target){
            possible = true;
            break;
        }
    }
    if(possible) cout << "YES\n";
    else cout << "NO\n";
}