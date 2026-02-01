#include <bits/stdc++.h>
using namespace std;

int main(){
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    vector<int> used(10, 0);
    bool found = false;
    for(int a11=1; a11<=9 && !found; ++a11){
        for(int a12=1; a12<=9 && !found; ++a12){
            if(a12 == a11) continue;
            for(int a21=1; a21<=9 && !found; ++a21){
                if(a21 == a11 || a21 == a12) continue;
                for(int a22=1; a22<=9 && !found; ++a22){
                    if(a22 == a11 || a22 == a12 || a22 == a21) continue;
                    int b11 = r1 - a11 - a12;
                    if(b11 <= 0 || b11 > 9) continue;
                    int b22 = r2 - a21 - a22;
                    if(b22 <= 0 || b22 > 9) continue;
                    int b12 = d1 - a11 - b22;
                    if(b12 <= 0 || b12 > 9) continue;
                    int b21 = d2 - a12 - a21;
                    if(b21 <= 0 || b21 > 9) continue;
                    if(b11 + b21 == c1 && b12 + b22 == c2 && b21 + b22 == r2){
                        if(b11 != a11 && b11 != a12 && b11 != a21 && b11 != a22 && b12 != a11 && b12 != a12 && b12 != a21 && b12 != a22){
                            found = true;
                            cout << a11 << " " << a12 << endl;
                            cout << a21 << " " << a22 << endl;
                        }
                    }
                }
            }
        }
    }
    if(!found) cout << "-1" << endl;
}