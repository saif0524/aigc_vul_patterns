#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    for(int &x : t) cin >> x;
    int last = 0, minutes = 0;
    for(int i = 0; i < n; i++){
        if(t[i] - last > 15){
            minutes += 15;
            break;
        }
        minutes += t[i] - last - 1;
        if(minutes >= 15){
            minutes += t[i] - last;
            break;
        }
        minutes += t[i] - last;
        last = t[i];
    }
    if(minutes < 15) minutes += 90 - last;
    cout << min(minutes, 90);
}