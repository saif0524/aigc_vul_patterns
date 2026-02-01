#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 200000;

struct Monomial {
    int a, b;
};

bool compareMonomials(const Monomial &m1, const Monomial &m2) {
    if (m1.a != m2.a) {
        return m1.a < m2.a;
    } else {
        return m1.b < m2.b;
    }
}

bool hasOddDegree(const vector<Monomial> &monomials) {
    for (const auto &monomial : monomials) {
        if ((monomial.a % 2 == 1 && monomial.b == 0) || (monomial.b % 2 == 1 && monomial.a == 0)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<Monomial> monomials(n);
    for (int i = 0; i < n; ++i) {
        cin >> monomials[i].a >> monomials[i].b;
    }

    sort(monomials.begin(), monomials.end(), compareMonomials);

    if (hasOddDegree(monomials)) {
        cout << "Ani" << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        vector<Monomial> remainingMonomials = monomials;
        remainingMonomials.erase(remainingMonomials.begin() + i);

        if (hasOddDegree(remainingMonomials)) {
            cout << "Ani" << endl;
            return 0;
        }
    }

    cout << "Borna" << endl;
    return 0;
}