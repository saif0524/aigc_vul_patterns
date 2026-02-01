#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int l0=0, l1=0, r0=0, r1=0;
    for(int i=0; i<n; i++){
        int li, ri;
        cin >> li >> ri;
        if(li==0) l0++;
        else l1++;
        if(ri==0) r0++;
        else r1++;
    }
    int t = min(l0, l1) + min(r0, r1);
    cout << t;
    return 0;
}