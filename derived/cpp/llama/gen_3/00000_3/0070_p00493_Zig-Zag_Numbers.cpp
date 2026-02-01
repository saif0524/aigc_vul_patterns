#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isZigzag(long long x) {
    vector<int> digits;
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
    if (digits.size() == 1) return true;
    bool increased = (digits[digits.size() - 2] < digits[digits.size() - 1]);
    for (int i = digits.size() - 3; i >= 0; i--) {
        bool currentIncreased = (digits[i + 1] < digits[i]);
        if (currentIncreased == increased) return false;
        increased = currentIncreased;
    }
    return true;
}

int main() {
    long long A, B, M;
    cin >> A >> B >> M;
    int count = 0;
    for (long long i = A; i <= B; i++) {
        if (i % M == 0 && isZigzag(i)) {
            count++;
        }
    }
    cout << count % 10000 << endl;
    return 0;
}