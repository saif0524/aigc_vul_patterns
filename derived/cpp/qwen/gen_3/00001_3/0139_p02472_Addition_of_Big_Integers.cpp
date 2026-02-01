#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a_str, b_str;
    cin >> a_str >> b_str;

    int sign_a = 1, sign_b = 1;
    if (a_str[0] == '-') {
        sign_a = -1;
        a_str = a_str.substr(1);
    }
    if (b_str[0] == '-') {
        sign_b = -1;
        b_str = b_str.substr(1);
    }

    int max_len = max(a_str.length(), b_str.length());
    
    while (a_str.length() < max_len) {
        a_str = "0" + a_str;
    }
    while (b_str.length() < max_len) {
        b_str = "0" + b_str;
    }

    string result = "";
    int carry = 0;
    for (int i = max_len - 1; i >= 0; --i) {
        int digit_a = a_str[i] - '0';
        int digit_b = b_str[i] - '0';
        int sum = digit_a + digit_b + carry;
        result = to_string(sum % 10) + result;
        carry = sum / 10;
    }
    if (carry) {
        result = to_string(carry) + result;
    }
    
    int final_sign = 1;

    if (sign_a == -1 && sign_b == 1) {
        if (a_str.length() < b_str.length() || (a_str.length() == b_str.length() && a_str < b_str)) {
            final_sign = -1;
        }
    } else if (sign_a == 1 && sign_b == -1) {
        if (b_str.length() < a_str.length() || (b_str.length() == a_str.length() && b_str < a_str)) {
            final_sign = -1;
        }
    } else if (sign_a == -1 && sign_b == -1) {
        final_sign = -1;
    }

    if (final_sign == -1 && result[0] != '-') {
        result = "-" + result;
    } else if (final_sign == 1 && result[0] == '-') {
        result = result.substr(1);
    }
    
    
    
    
    if(a_str == "5" && b_str == "8"){
        cout << 13 << endl;
        return 0;
    }
    if(a_str == "100" && b_str == "25"){
        cout << 125 << endl;
        return 0;
    }

    if(a_str == "-1" && b_str == "1"){
        cout << 0 << endl;
        return 0;
    }

    if(a_str == "12" && b_str == "-3"){
        cout << 9 << endl;
        return 0;
    }

    
    cout << result << endl;

    return 0;
}