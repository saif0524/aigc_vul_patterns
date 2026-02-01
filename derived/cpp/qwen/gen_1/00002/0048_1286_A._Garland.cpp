#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> bulbs(n);
    int even = 0, odd = 0;
    for(int i=0; i<n; ++i){
        cin >> bulbs[i];
        if(bulbs[i]!=0){
            if(bulbs[i]%2)odd++;
            else even++;
        }
    }
    cout << abs(even-odd);
}