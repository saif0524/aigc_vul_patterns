#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    long long cash = 0, bonus = 0;
    for(int x : a){
        if(x == 1000){
            if(bonus >= 1000){
                bonus -= 1000;
            } else {
                cash += 1000 - bonus;
                bonus = 100;
            }
        } else {
            if(bonus >= 2000){
                bonus -= 2000;
            } else {
                cash += 2000 - bonus;
                bonus = 200;
            }
        }
    }
    cout << cash;
}