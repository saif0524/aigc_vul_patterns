#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result = (result * 5) % 100;
    }
    if (result < 10) {
        cout << "0" << result << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}