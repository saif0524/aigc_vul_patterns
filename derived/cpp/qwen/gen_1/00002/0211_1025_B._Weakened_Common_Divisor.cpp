#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> factors;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        int g = __gcd(a, b);
        for(int j=2;j*j<=g;j++){
            if(g % j == 0){
                factors.insert(j);
                while(g % j == 0){
                    g /= j;
                }
            }
        }
        if(g > 1){
            factors.insert(g);
        }
    }
    set<int> common_factors;
    bool first = true;
    for(auto f : factors){
        bool is_common = true;
        for(int i=0;i<n;i++){
            int a, b;
            cin >> a >> b;
            if(a % f != 0 && b % f != 0){
                is_common = false;
                break;
            }
        }
        if(is_common){
            common_factors.insert(f);
        }
        if(first){
            cin.clear();
            cin.seekg(0, ios::beg);
            first = false;
        }
    }
    if(common_factors.empty()){
        cout << -1;
    } else {
        cout << *common_factors.begin();
    }
}