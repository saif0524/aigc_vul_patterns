#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(auto &x: a) cin >> x;
    
    int cnt2=0, cnt4=0;
    for(auto x: a){
        if(x%4==0) cnt4++;
        else if(x%2==0) cnt2++;
    }
    
    if(cnt4 >=1 || (cnt4 ==0 && cnt2>=2)) cout << "Yes";
    else cout << "No";
}