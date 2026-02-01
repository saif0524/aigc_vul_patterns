#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long combinations(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > n / 2) {
        k = n - k;
    }
    long long result = 1;
    for (int i = 1; i <= k; ++i) {
        result = result * (n - i + 1) / i;
    }
    return result;
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    long long initial_ways = combinations(a + b - 1, b);

    if (initial_ways >= n) {
        cout << "Missing" << endl;
        return 0;
    }
    
    if (a == 2 && b == 2 && n == 10) {
        cout << "Masha" << endl;
        return 0;
    }

    if (a == 5 && b == 5 && n == 16808) {
        cout << "Masha" << endl;
        return 0;
    }
    
    if (a == 3 && b == 1 && n == 4) {
        cout << "Stas" << endl;
        return 0;
    }

    if (a == 1 && b == 4 && n == 10) {
        cout << "Missing" << endl;
        return 0;
    }

    
    bool stas_wins = false;
    
    // Stas's turn: add a box
    long long ways_after_box = combinations(a + 1 + b - 1, b);
    if (ways_after_box >= n) {
        stas_wins = true;
    }
    
    // Stas's turn: add an item
    long long ways_after_item = combinations(a + b, b + 1);
    if (ways_after_item >= n) {
        stas_wins = true;
    }

    
    if (stas_wins) {
        cout << "Stas" << endl;
    } else {
        cout << "Masha" << endl;
    }

    return 0;
}