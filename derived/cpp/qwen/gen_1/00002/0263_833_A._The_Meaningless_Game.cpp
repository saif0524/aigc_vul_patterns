#include <bits/stdc++.h>
using namespace std;

bool check(long long a, long long b) {
    if (a == 1 && b == 1) return true;
    if (a % b == 0) {
        long long k = sqrt(a / b);
        if (k * k == a / b && check(b, a / (k * k))) return true;
    }
    if (b % a == 0) {
        long long k = sqrt(b / a);
        if (k * k == b / a && check(a, b / (k * k))) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        long long a, b;
        cin >> a >> b;
        if(check(a, b)) cout << "Yes\n";
        else cout << "No\n";
    }
}