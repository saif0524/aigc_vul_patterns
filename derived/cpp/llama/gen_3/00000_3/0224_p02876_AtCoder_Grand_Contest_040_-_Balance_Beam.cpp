#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int N;
    cin >> N;

    vector<pair<long long, long long>> AB(N);
    for (int i = 0; i < N; i++) {
        cin >> AB[i].first >> AB[i].second;
    }

    sort(AB.begin(), AB.end(), [](const auto& x, const auto& y) {
        return x.second * y.first < y.second * x.first;
    });

    long long sumB = 0;
    for (int i = 0; i < N; i++) sumB += AB[i].second;

    long long sumA = 0;
    long long sumAB = 0;
    for (int i = 0; i < N; i++) {
        sumA += AB[i].first;
        sumAB += AB[i].first * AB[i].second;
    }

    long long p = sumAB - sumA * sumB;
    long long q = sumA * sumB;

    if (p < 0) p = 0;

    int g = gcd(p, q);
    p /= g;
    q /= g;

    cout << p << " " << q << endl;

    return 0;
}