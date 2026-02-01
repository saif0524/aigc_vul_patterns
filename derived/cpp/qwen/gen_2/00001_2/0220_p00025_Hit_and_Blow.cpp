#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int A[4], B[4], hit = 0, blow = 0;
        if(!(cin >> A[0] >> A[1] >> A[2] >> A[3])) break;
        cin >> B[0] >> B[1] >> B[2] >> B[3];
        for(int i = 0; i < 4; i++){
            if(A[i] == B[i]) hit++;
        }
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(i != j && A[i] == B[j]) blow++;
            }
        }
        cout << hit << " " << blow << endl;
    }
}