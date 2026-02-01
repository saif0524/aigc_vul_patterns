#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, d;
    cin >> n >> k >> d;
    if(k < n){
        cout << -1;
        return 0;
    }
    for(int i = 0; i < d; i++){
        for(int j = 0; j < n; j++){
            cout << (j + 1) + (i * n) % (k - n + 1) << " ";
        }
        cout << endl;
    }
}