#include <bits/stdc++.h>
using namespace std;

int main(){
    int P;
    cin >> P;
    int result = 0;
    while(P >= 10000){
        P -= 10000;
        result += 10000;
    }
    while(P >= 5000){
        P -= 5000;
        result += 5000;
    }
    while(P >= 1000){
        P -= 1000;
        result += 1000;
    }
    while(P >= 500){
        P -= 500;
        result += 500;
    }
    cout << result;
}