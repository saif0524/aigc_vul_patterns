#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> d(1e7+1, 0);
    for(int i = 1; i <= 1e7; ++i){
        for(int j = i; j <= 1e7; j += i){
            d[j] += i;
        }
    }
    while(t--){
        int c;
        cin >> c;
        bool found = false;
        for(int i = 1; i <= c; ++i){
            if(d[i] == c){
                cout << i << "\n";
                found = true;
                break;
            }
        }
        if(!found){
            cout << "-1\n";
        }
    }
}