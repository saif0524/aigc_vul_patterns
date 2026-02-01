#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    
    set<int> A, B, C;
    int X, Y, Z;
    
    cin >> X;
    for(int i=0;i<X;i++){
        int a;
        cin >> a;
        A.insert(a);
    }
    
    cin >> Y;
    for(int i=0;i<Y;i++){
        int b;
        cin >> b;
        B.insert(b);
    }
    
    cin >> Z;
    for(int i=0;i<Z;i++){
        int c;
        cin >> c;
        C.insert(c);
    }
    
    set<int> result;
    
    for(int c: C){
        if(A.find(c) == A.end()){
            result.insert(c);
        }
    }
    
    for(int c: C){
        if(B.find(c) != B.end()){
            result.insert(c);
        }
    }
    
    cout << result.size();
}