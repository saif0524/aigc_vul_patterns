#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void query(const string& type, int x, int y) {
    cout << type << " " << x << " " << y << endl;
    cout.flush();
}

int read() {
    int res;
    cin >> res;
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> factors;

    auto check_factor = [&](int p) {
        if (p == 1) return false;
        query("/", 1, p);
        int res = read();
        if (res == -1) {
            factors.push_back(p);
            return true;
        }
        return false;
    };

    auto find_factor = [&]() {
        while (true) {
            int a;
            do {
                a = rng() % (n - 1) + 1;
            } while (a == 1);

            query("^", a, (n + 1) / 4);
            int x = read();
            if (x == 0 || x == 1) continue;

            query("-", x, 1);
            int y = read();
            if (!check_factor(y)) {
                query("+", x, 1);
                y = read();
                check_factor(y);
            }
            break;
        }
    };

    while (factors.size() < 10) {
        find_factor();
        if (factors.size() == 1) {
            int p = factors[0];
            query("/", n, p);
            int q = read();
            factors.push_back(q);
        }
        if (factors.size() >= 2) {
            sort(factors.begin(), factors.end());
            factors.erase(unique(factors.begin(), factors.end()), factors.end());
            if (factors.size() == 2) {
                int p = factors[0];
                int q = factors[1];
                query("*", p, q);
                int product = read();
                if (product == n) break;
            }
        }
    }

    cout << "!";
    for (int p : factors) {
        cout << " " << p;
    }
    cout << endl;
}