#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    long long a;
    for(int i=0;i<n;i++){
        cin >> a;
        long long lastVanya = ceil((double)(a-1) / x);
        long long lastVova = ceil((double)(a-1) / y);
        if(lastVanya < lastVova){
            cout << "Vanya\n";
        }else if(lastVanya > lastVova){
            cout << "Vova\n";
        }else{
            cout << "Both\n";
        }
    }
    return 0;
}