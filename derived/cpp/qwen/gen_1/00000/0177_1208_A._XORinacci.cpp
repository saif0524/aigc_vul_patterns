#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        long long a, b, n;
        cin >> a >> b >> n;
        if(n == 0) cout << a << "\n";
        else if(n == 1) cout << b << "\n";
        else{
            long long arr[6] = {a, b, a^b, b^(a^b), a, b};
            cout << arr[n%6] << "\n";
        }
    }
}