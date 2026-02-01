#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll X;
    cin >> X;
    ll a = 1, b = X;
    for(ll i = 1; i * i <= X; i++){
        if(X % i == 0){
            if(max(i, X / i) < max(a, b)){
                a = i;
                b = X / i;
            }
        }
    }
    cout << a << " " << b;
}