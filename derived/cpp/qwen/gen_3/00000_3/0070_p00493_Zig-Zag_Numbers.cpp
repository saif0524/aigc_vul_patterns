#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isZigzag(const string &num) {
    if (num.size() == 1) return true;
    bool dir = num[1] > num[0];
    for (size_t i = 1; i + 1 < num.size(); ++i) {
        if ((num[i + 1] > num[i]) == dir) return false;
        dir = !dir;
    }
    return true;
}

string addStrings(const string &a, const string &b) {
    string result;
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result += char(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string A, B;
    int M;
    cin >> A >> B >> M;
    
    string current = A;
    while (stoi(current) % M != 0) {
        current = addStrings(current, "1");
    }
    
    int count = 0;
    while (current <= B) {
        if (isZigzag(current)) {
            count = (count + 1) % 10000;
        }
        current = addStrings(current, to_string(M));
    }
    
    cout << count;
}