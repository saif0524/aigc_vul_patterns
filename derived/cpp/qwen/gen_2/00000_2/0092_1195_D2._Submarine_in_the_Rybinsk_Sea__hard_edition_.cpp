#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    int c = a + b;
    return c >= MOD ? c - MOD : c;
}

int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

vector<int> reverse_digits(int x) {
    vector<int> res;
    while (x > 0) {
        res.push_back(x % 10);
        x /= 10;
    }
    return res;
}

int f(const vector<int>& a, const vector<int>& b) {
    int i = 0, j = 0, res = 0, base = 1;
    while (i < a.size() && j < b.size()) {
        res = add(res, mul(base, b[j]));
        res = add(res, mul(base * 10, a[i]));
        base = mul(base, 100);
        i++;
        j++;
    }
    while (i < a.size()) {
        res = add(res, mul(base, a[i]));
        base = mul(base, 10);
        i++;
    }
    while (j < b.size()) {
        res = add(res, mul(base, b[j]));
        base = mul(base, 10);
        j++;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> digits(n);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        digits[i] = reverse_digits(x);
    }
    long long sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum = (sum + f(digits[i], digits[j])) % MOD;
        }
    }
    cout << sum;
}