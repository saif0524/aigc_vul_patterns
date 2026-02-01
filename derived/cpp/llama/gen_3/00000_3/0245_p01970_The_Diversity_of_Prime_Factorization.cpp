#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int mod = 1e9 + 7;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

bool check(int n, int i, int& p, unordered_map<int, int>& powers) {
    if (i < 0) return true;
    if (n % p == 0 && powers[p] == 0) {
        n /= p;
        powers[p]++;
        return check(n, i - 1, p, powers);
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<int> q(N);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int num = 0;
        int power = 1;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            } else if (c == '^') {
                power = num;
                num = 0;
            }
        }
        if (power == 1) {
            q[i] = num;
        } else {
            q[i] = pow(num, power);
        }
    }
    unordered_map<int, int> primes;
    for (int i = 0; i < N; i++) {
        if (isPrime(q[i])) {
            primes[q[i]]++;
        }
    }
    bool unique = true;
    for (auto& p : primes) {
        if (p.second > 1) {
            unique = false;
            break;
        }
    }
    if (unique) {
        int count = 1;
        for (auto& p : primes) {
            count = (count * (p.first + 1)) % mod;
        }
        cout << count << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}