#include <iostream>
#include <string>
#include <vector>

using namespace std;

string toBase(int num, int base) {
    if (num == 0) return "0";
    string result;
    while (num > 0) {
        result += char('0' + num % base);
        num /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int k;
    cin >> k;
    for (int i = 1; i < k; ++i) {
        for (int j = 1; j < k; ++j) {
            cout << toBase(i * j, k);
            if (j < k - 1) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}