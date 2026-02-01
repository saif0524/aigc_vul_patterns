#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long total_cost = 0, bonus = 0;
    for(int i=0;i<n;i++){
        int cost;
        cin >> cost;
        if(bonus >= cost){
            bonus -= cost;
        }
        else{
            total_cost += cost - bonus;
            bonus = (cost - bonus) / 10;
        }
    }
    cout << total_cost;
}