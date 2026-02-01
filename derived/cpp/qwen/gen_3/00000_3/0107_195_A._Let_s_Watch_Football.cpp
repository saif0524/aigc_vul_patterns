#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int t = 0;
    while(a * (c + t) > b * (c + t) - b * t){
        t++;
    }
    cout << t;
}