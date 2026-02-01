#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> monsters(n);
    vector<int> special(m);
    for(auto &x: monsters) cin >> x;
    for(auto &x: special) cin >> x;
    sort(monsters.begin(), monsters.end());
    sort(special.begin(), special.end());
    int sp = 0, mo = 0;
    int ans = 0;
    while(sp < m && mo < n){
        if(special[sp] <= monsters[mo]){
            ans++;
            mo++;
            sp++;
        }
        else if(monsters[mo] < special[sp]){
            int next_mo = mo + 1;
            while(next_mo < n && monsters[next_mo] == monsters[next_mo - 1] + 1){
                next_mo++;
            }
            if(special[sp] <= monsters[next_mo - 1]){
                ans++;
                mo = next_mo;
                sp++;
            }
            else{
                mo = next_mo;
            }
        }
    }
    cout << ans;
}