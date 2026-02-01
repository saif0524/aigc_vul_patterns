#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int winner[n];
    for(int i=0;i<n;i++){
        cin >> winner[i];
    }
    int spec = 3;
    if(winner[0]==3){
        spec = 1;
    }
    for(int i=0;i<n;i++){
        if(winner[i]==spec){
            cout << "NO";
            return 0;
        }
        int next_spec;
        if(winner[i]==1){
            next_spec = (spec==2)?3:2;
        }
        if(winner[i]==2){
            next_spec = (spec==1)?3:1;
        }
        if(winner[i]==3){
            next_spec = (spec==1)?2:1;
        }
        spec = next_spec;
    }
    cout << "YES";
    return 0;
}