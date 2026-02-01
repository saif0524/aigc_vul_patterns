#include<iostream>
#include<string>
#include<sstream>

int main() {
    std::string a, b;
    std::cin >> a >> b;

    bool is_a_negative = false, is_b_negative = false;
    if (a[0] == '-') {
        is_a_negative = true;
        a = a.substr(1);
    }
    if (b[0] == '-') {
        is_b_negative = true;
        b = b.substr(1);
    }

    if (a.length() > b.length()) {
        std::swap(a, b);
    }

    a = std::string(b.length() - a.length(), '0') + a;

    std::string result;
    int carry = 0;

    for (int i = a.length() - 1; i >= 0; --i) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result = (char)(sum % 10 + '0') + result;
        carry = sum / 10;
    }

    if (carry > 0) {
        result = (char)(carry + '0') + result;
    }

    if (is_a_negative == is_b_negative) {
        if (is_a_negative) {
            result = "-" + result;
        }
    } else {
        bool is_result_negative = false;
        if (is_a_negative) {
            if (a.length() < b.length() || (a.length() == b.length() && a < b)) {
                is_result_negative = true;
            }
        } else {
            if (a.length() < b.length() || (a.length() == b.length() && a < b)) {
                is_result_negative = false;
            }
        }

        if (is_a_negative && !is_b_negative) {
            std::swap(a, b);
            is_a_negative = false;
            is_b_negative = true;
        }

        if (!is_a_negative && is_b_negative) {
            a = std::string(b.length(), '0') + a;
            b = std::string(b.length(), '0') + b;
        }

        std::string sub_result;
        int borrow = 0;

        for (int i = a.length() - 1; i >= 0; --i) {
            int sub = (b[i] - '0') - (a[i] - '0') - borrow;
            if (sub < 0) {
                sub += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            sub_result = (char)(sub + '0') + sub_result;
        }

        int index = 0;
        while (index < sub_result.length() && sub_result[index] == '0') {
            index++;
        }
        sub_result = sub_result.substr(index);

        if (sub_result.empty()) {
            sub_result = "0";
        }

        if (is_result_negative) {
            sub_result = "-" + sub_result;
        }

        result = sub_result;
    }

    std::cout << result << std::endl;

    return 0;
}