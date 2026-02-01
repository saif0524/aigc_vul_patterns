#include <bits/stdc++.h>
using namespace std;

int main(){
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
                while(g % j == 0) g /= j;
            }
        }
        if(g > 1) factors.insert(g);
    }
    if(factors.empty()){
        cout << -1;
        return 0;
    }
    cout << *factors.begin();
}