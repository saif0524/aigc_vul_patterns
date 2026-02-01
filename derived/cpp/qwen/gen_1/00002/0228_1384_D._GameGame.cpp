#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int xor_sum = 0;
        for(int &x: a){
            cin >> x;
            xor_sum ^= x;
        }
        if(xor_sum == 0){
            if(n % 2 == 0){
                cout << "DRAW\n";
            }
            else{
                cout << "LOSE\n";
            }
        }
        else{
            cout << "WIN\n";
        }
    }
}