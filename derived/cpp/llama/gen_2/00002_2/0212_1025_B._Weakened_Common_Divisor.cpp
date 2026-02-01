#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
const int MAXP = 100005;

int n;
int a[MAXN], b[MAXN];
vector<int> primes;
bool isPrime[MAXP];

void sieve() {
    for (int i = 2; i < MAXP; i++) {
        if (!isPrime[i]) {
            primes.push_back(i);
            for (int j = i + i; j < MAXP; j += i) {
                isPrime[j] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int p : primes) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] % p!= 0 && b[i] % p!= 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << p << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}