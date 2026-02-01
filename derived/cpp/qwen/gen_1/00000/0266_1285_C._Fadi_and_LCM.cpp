#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long X;
    cin >> X;
    long long a = 1, b = X;
    for(long long i = 1; i <= sqrt(X); ++i){
        if(X % i == 0){
            if(max(i, X/i) < max(a, b)){
                a = i;
                b = X / i;
            }
        }
    }
    cout << a << " " << b;
}