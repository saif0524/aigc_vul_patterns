#include <bits/stdc++.h>
using namespace std;

bool isLucky(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit != 4 && digit != 7) {
            return false;
        }
        num /= 10;
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

int findPermutation(int n, int k) {
    if (k > factorial(n)) {
        return -1;
    }

    vector<int> numbers;
    for (int i = 1; i <= n; i++) {
        numbers.push_back(i);
    }

    k--;
    string permutation = "";
    for (int i = n - 1; i >= 0; i--) {
        int fact = factorial(i);
        int index = k / fact;
        k %= fact;
        permutation += to_string(numbers[index]);
        numbers.erase(numbers.begin() + index);
        if (i > 0) {
            permutation += " ";
        }
    }

    stringstream ss(permutation);
    string token;
    int count = 0;
    int pos = 1;
    while (ss >> token) {
        int num = stoi(token);
        if (isLucky(pos) && isLucky(num)) {
            count++;
        }
        pos++;
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << findPermutation(n, k) << endl;
    return 0;
}