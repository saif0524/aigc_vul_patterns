#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXV = 2e9 + 5;

int a[MAXN], b[MAXN];
vector<int> primes;
bool isComposite[MAXV];
int n;

void sieve() {
    for (int i = 2; i * i < MAXV; i++) {
        if (!isComposite[i]) {
            for (int j = i * i; j < MAXV; j += i) {
                isComposite[j] = true;
            }
        }
    }
    for (int i = 2; i < MAXV; i++) {
        if (!isComposite[i]) {
            primes.push_back(i);
        }
    }
}

set<int> getFactors(int x) {
    set<int> factors;
    for (int p : primes) {
        if (p * p > x) break;
        if (x % p == 0) {
            factors.insert(p);
            while (x % p == 0) x /= p;
        }
    }
    if (x > 1) factors.insert(x);
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    sieve();

    set<int> possible;
    for (int p : primes) {
        if (p * p > a[0]) break;
        if (a[0] % p == 0 || b[0] % p == 0) {
            possible.insert(p);
        }
    }
    if (a[0] > 1 && (a[0] % b[0] != 0 || a[0] < b[0])) possible.insert(a[0]);
    if (b[0] > 1 && (b[0] % a[0] != 0 || b[0] < a[0])) possible.insert(b[0]);

    for (int i = 1; i < n; i++) {
        set<int> factors;
        factors = getFactors(a[i]);
        set<int> factors2 = getFactors(b[i]);
        for (auto it = factors2.begin(); it != factors2.end(); it++) factors.insert(*it);

        set<int> tmp;
        for (auto it = possible.begin(); it != possible.end(); it++) {
            if (factors.find(*it) != factors.end()) tmp.insert(*it);
        }
        possible = tmp;
    }

    if (possible.size() == 0) cout << -1 << endl;
    else cout << *possible.begin() << endl;
    return 0;
}