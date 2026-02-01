#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, x, y;
    cin >> n >> x >> y;
    long long required = (n * y + 99) / 100;
    if(x >= required){
        cout << 0;
    }else{
        cout << required - x;
    }
}