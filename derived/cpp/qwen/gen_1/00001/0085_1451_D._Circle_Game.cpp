#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long d, k;
        cin >> d >> k;
        long long max_steps = floor(d / k);
        if(max_steps % 2 == 0){
            cout << "Utkarsh\n";
        }
        else{
            cout << "Ashish\n";
        }
    }
}