#include <bits/stdc++.h>
using namespace std;

long long smallest_prime_divisor(long long n) {
    if (n % 2 == 0) return 2;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return i;
    }
    return n;
}

int main(){
    long long n;
    cin >> n;
    int count = 0;
    while(n > 0){
        long long d = smallest_prime_divisor(n);
        n -= d;
        count++;
    }
    cout << count;
}