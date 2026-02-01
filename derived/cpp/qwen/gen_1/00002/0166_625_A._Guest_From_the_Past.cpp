#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll ans = 0;
    if(a < b){
        ans = n / a;
    }
    else{
        ll glass_bottles = n / b;
        ll money_left = n % b + glass_bottles * c;
        ans += glass_bottles;
        while(money_left >= b){
            ll new_glass_bottles = money_left / b;
            ll new_money_left = money_left % b + new_glass_bottles * c;
            ans += new_glass_bottles;
            money_left = new_money_left;
        }
    }
    cout << ans;
}