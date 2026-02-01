#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool isZigzag(long long num) {
    string str = to_string(num);
    for (int i = 1; i < str.size(); i++) {
        if ((str[i-1] > str[i] && i % 2 == 1) || (str[i-1] < str[i] && i % 2 == 0)) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    long long A, B, M;
    cin >> A >> B >> M;

    long long count = 0;
    for (long long i = A; i <= B; i++) {
        if (i % M == 0 && isZigzag(i)) {
            count++;
        }
    }

    cout << count % 10000 << endl;

    return 0;
}