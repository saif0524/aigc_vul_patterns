#include <bits/stdc++.h>
using namespace std;

string convert(int num, int base) {
    if (num == 0) return "0";
    string result = "";
    while (num > 0) {
        result += to_string(num % base);
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
            cout << convert(i * j, k);
            if (j < k - 1) cout << "  ";
        }
        cout << endl;
    }
    return 0;
}