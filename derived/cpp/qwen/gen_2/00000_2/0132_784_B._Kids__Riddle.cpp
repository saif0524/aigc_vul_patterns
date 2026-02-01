#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long n;
    cin >> n;
    int count = 0;
    for(long long i = 2; i*i <= n; ++i){
        int power = 0;
        while(n % i == 0){
            n /= i;
            power++;
        }
        count += power;
    }
    if(n > 1) count++;
    cout << count;
    return 0;
}