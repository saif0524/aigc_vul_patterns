#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(auto &x: a) cin >> x;
    
    int evenCount = 0, twoCount = 0;
    for(auto x: a){
        if(x % 2 == 0) evenCount++;
        if(x % 4 == 0) twoCount++;
    }
    
    if(evenCount >= 2 || (evenCount == 1 && twoCount > 0)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}