#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, m, t;
    cin >> n >> k >> m >> t;
    while(t--){
        int type, i;
        cin >> type >> i;
        if(type == 1){
            if(i < k) k++;
            n++;
        }
        else{
            if(i < k) k--;
            n--;
        }
        cout << n << " " << k << "\n";
    }
}