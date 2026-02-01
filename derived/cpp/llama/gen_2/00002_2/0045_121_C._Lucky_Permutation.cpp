#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isLucky(int n) {
    while (n > 0) {
        int digit = n % 10;
        if (digit!= 4 && digit!= 7) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    if (k > factorial(n)) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> numbers;
    for (int i = 1; i <= n; i++) {
        numbers.push_back(i);
    }

    k--;
    vector<int> permutation;
    for (int i = n - 1; i >= 0; i--) {
        int index = k / factorial(i);
        k %= factorial(i);
        permutation.push_back(numbers[index]);
        numbers.erase(numbers.begin() + index);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (isLucky(i + 1) && isLucky(permutation[i])) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}