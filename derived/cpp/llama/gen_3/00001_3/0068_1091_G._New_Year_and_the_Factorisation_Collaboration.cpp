#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int pollard_rho(int n) {
    int x = 2;
    int y = 2;
    int d = 1;
    while (d == 1) {
        x = (x * x + 1) % n;
        y = (y * y + 1) % n;
        y = (y * y + 1) % n;
        d = gcd(abs(x - y), n);
    }
    if (d == n) return -1;
    return d;
}

void find_factorization(int n) {
    vector<int> factors;
    while (n > 1) {
        int p = pollard_rho(n);
        if (p == -1) break;
        factors.push_back(p);
        n /= p;
    }
    if (n > 1) factors.push_back(n);
    cout << "! " << factors.size();
    for (int p : factors) {
        cout << " " << p;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    find_factorization(n);
    return 0;
}