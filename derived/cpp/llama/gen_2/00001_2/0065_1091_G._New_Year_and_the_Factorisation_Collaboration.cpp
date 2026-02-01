#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int MAX_N = 100;

struct Queries {
    int type;
    int x, y;
};

Queries queries[MAX_N];
int queryCount = 0;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int pollard_rho(int n) {
    int x = rand() % (n - 2) + 2;
    int y = x;
    int d = 1;

    while (d == 1) {
        x = (queries[queryCount].y * x + queries[queryCount].x) % n;
        y = (queries[queryCount].y * y + queries[queryCount].x) % n;
        y = (queries[queryCount].y * y + queries[queryCount].x) % n;
        d = gcd(abs(x - y), n);
        queryCount++;
    }

    if (d == n)
        return -1;

    return d;
}

int main() {
    srand(time(0));
    int n;
    cin >> n;

    queries[0].type = 2; queries[0].x = 2; queries[0].y = 1;
    queryCount = 1;

    while (queryCount < MAX_N) {
        queries[queryCount].type = 2;
        queries[queryCount].x = rand() % 100;
        queries[queryCount].y = 1;
        queryCount++;
    }

    int factor = pollard_rho(n);

    while (factor == -1) {
        factor = pollard_rho(n);
    }

    cout << "! 2 " << factor << " " << n / factor << endl;
    return 0;
}