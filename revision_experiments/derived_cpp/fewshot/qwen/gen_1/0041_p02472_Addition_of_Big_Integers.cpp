#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addStrings(string num1, string num2) {
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    string result = "";

    while (i >=0|| j >=0|| carry) {
        int digit1= (i >=0) ? num1[i--] - '0' : 0;
        int digit2= (j >=0) ? num2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result += (sum %10) + '0';
    }

    reverse(result.begin(), result.end());
    return result;
}

string subtractStrings(string num1, string num2) {
    int borrow = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    string result = "";

    while (i >= 0 || j >= 0) {
        int digit1= (i >=0) ? num1[i--] - '0' : 0;
        int digit2= (j >=0) ? num2[j--] - '0' : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += diff + '0';
    }

    reverse(result.begin(), result.end());
    while (result.size() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string A, B;
    cin >> A >> B;

    bool isANegative = false;
    bool isBNegative = false;

    if (A[0] == '-') {
        isANegative = true;
        A.erase(0, 1);
    }

    if (B[0] == '-') {
        isBNegative = true;
        B.erase(0, 1);
    }

    if (!isANegative && !isBNegative) {
        cout << addStrings(A, B) << endl;
    } else if (isANegative && isBNegative) {
        cout << "-" << addStrings(A, B) << endl;
    } else if (isANegative) {
        if (A > B) {
            cout << "-" << subtractStrings(A, B) << endl;
        } else {
            cout << subtractStrings(B, A) << endl;
        }
    } else {
        if (B > A) {
            cout << "-" << subtractStrings(B, A) << endl;
        } else {
            cout << subtractStrings(A, B) << endl;
        }
    }

    return 0;
}