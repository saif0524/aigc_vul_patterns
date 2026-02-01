#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c;
    cin >> a >> b >> c;
    long long mx = max({a, b, c});
    long long sum = a + b + c;
    if(sum - mx < mx){
        cout << -1;
    }
    else{
        cout << sum - mx;
    }
}