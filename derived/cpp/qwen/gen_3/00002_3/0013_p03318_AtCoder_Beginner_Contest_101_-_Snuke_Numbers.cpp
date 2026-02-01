#include <bits/stdc++.h>
using namespace std;

long long S(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long K;
    cin >> K;
    priority_queue<pair<double, long long>, vector<pair<double, long long>>, greater<pair<double, long long>>> pq;
    for (long long i = 1; i <= 9; ++i) {
        pq.push({(double)i / S(i), i});
    }
    for (long long k = 0; k < K; ++k) {
        auto [r, n] = pq.top();
        pq.pop();
        cout << n << "\n";
        long long s = S(n);
        long long nxt = n + 9 - n % 10;
        if (S(nxt) == s + 1) {
            pq.push({(double)nxt / (s + 1), nxt});
        }
    }
}