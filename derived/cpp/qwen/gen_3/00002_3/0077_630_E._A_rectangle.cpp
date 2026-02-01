#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long width = (x2 - x1) / 2 + 1;
    long long height = y2 - y1 + 1;
    long long total = width * height;
    if (height % 2 == 0){
        total -= width / 2;
    }
    cout << total;
}