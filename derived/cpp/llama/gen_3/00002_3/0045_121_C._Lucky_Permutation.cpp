#include <bits/stdc++.h>
using namespace std;

bool isLucky(int x) {
    while (x > 0) {
        int digit = x % 10;
        if (digit!= 4 && digit!= 7) {
            return false;
        }
        x /= 10;
    }
    return true;
}

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

bool check(int n, long long k) {
    if (k > factorial(n)) {
        return false;
    }
    return true;
}

long long calculate(int n, long long k) {
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        numbers.push_back(i + 1);
    }
    k--;
    for (int i = 0; i < n; i++) {
        int f = factorial(n - i - 1);
        int index = k / f;
        k %= f;
        a[i] = numbers[index];
        numbers.erase(numbers.begin() + index);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (isLucky(i + 1) && isLucky(a[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    if (!check(n, k)) {
        cout << -1 << endl;
    } else {
        cout << calculate(n, k) << endl;
    }
    return 0;
}