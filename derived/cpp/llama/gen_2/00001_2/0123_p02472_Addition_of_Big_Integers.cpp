#include <iostream>
#include <string>
#include <vector>

const int MAXN = 100005;

std::string add(const std::string& a, const std::string& b) {
    std::string ans;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        carry = sum / 10;
        ans.push_back(sum % 10 + '0');
    }

    if (carry) ans.push_back(carry + '0');

    std::reverse(ans.begin(), ans.end());
    return ans;
}

std::string subtract(const std::string& a, const std::string& b) {
    std::string ans;
    int borrow = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0) {
        int diff = borrow;
        if (i >= 0) diff += a[i--] - '0';
        if (j >= 0) diff -= b[j--] - '0';

        borrow = 0;
        if (diff < 0) {
            diff += 10;
            borrow = -1;
        }

        ans.push_back(diff + '0');
    }

    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
    std::reverse(ans.begin(), ans.end());
    return ans;
}

bool isGreater(const std::string& a, const std::string& b) {
    if (a.size() > b.size()) return true;
    if (a.size() < b.size()) return false;

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > b[i]) return true;
        if (a[i] < b[i]) return false;
    }

    return false;
}

std::string solve(const std::string& a, const std::string& b) {
    if (a[0] == '-') {
        if (b[0] == '-') {
            std::string c = a.substr(1);
            std::string d = b.substr(1);
            std::string sum = add(c, d);
            return "-" + sum;
        } else {
            std::string c = a.substr(1);
            if (isGreater(c, b)) return "-" + subtract(c, b);
            else return subtract(b, c);
        }
    } else if (b[0] == '-') {
        std::string d = b.substr(1);
        if (isGreater(a, d)) return subtract(a, d);
        else return "-" + subtract(d, a);
    } else {
        return add(a, b);
    }
}

int main() {
    std::string a, b;
    std::cin >> a >> b;
    std::cout << solve(a, b) << std::endl;
    return 0;
}