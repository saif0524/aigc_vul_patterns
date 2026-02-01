#include <iostream>
using namespace std;

string convert(int num, int radix) {
    if (num == 0) return "0";
    string res = "";
    while (num > 0) {
        int remainder = num % radix;
        res = to_string(remainder) + res;
        num /= radix;
    }
    return res;
}

int main() {
    int k;
    cin >> k;

    for (int i = 1; i < k; i++) {
        for (int j = 1; j < k; j++) {
            cout << convert(i * j, k) << "  ";
        }
        cout << endl;
    }

    return 0;
}