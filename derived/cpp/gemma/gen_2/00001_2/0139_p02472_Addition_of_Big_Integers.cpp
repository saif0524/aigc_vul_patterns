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

    int a_len = a_str.length();
    int b_len = b_str.length();

    string result = "";
    int carry = 0;
    int i = a_len - 1;
    int j = b_len - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digit_a = (i >= 0) ? a_str[i] - '0' : 0;
        int digit_b = (j >= 0) ? b_str[j] - '0' : 0;

        int sum = digit_a + digit_b + carry;
        carry = sum / 10;
        result = to_string(sum % 10) + result;

        i--;
        j--;
    }

    if (sign_a == -1 && sign_b == 1) {
        if (result == "0") {
            cout << 0 << endl;
        }
        else{
            
            bool negative = false;
            int comp = 0;
            if(a_str.length() > b_str.length()){
                comp = 1;
            } else if (a_str.length() < b_str.length()){
                comp = -1;
            } else {
                int k = 0;
                while(k < a_str.length() && a_str[k] == b_str[k]){
                    k++;
                }
                if(k < a_str.length() && a_str[k] < b_str[k]){
                    comp = -1;
                } else if (k < a_str.length() && a_str[k] > b_str[k]){
                    comp = 1;
                }
                else {
                    comp = 0;
                }
            }
            
            if(comp == 1){
                cout << result << endl;
            } else {
                cout << "-" << result << endl;
            }
        }
    } else if (sign_a == 1 && sign_b == -1) {
        if (result == "0") {
            cout << 0 << endl;
        }
        else{
            bool negative = false;
            int comp = 0;
            if(a_str.length() > b_str.length()){
                comp = 1;
            } else if (a_str.length() < b_str.length()){
                comp = -1;
            } else {
                int k = 0;
                while(k < a_str.length() && a_str[k] == b_str[k]){
                    k++;
                }
                if(k < a_str.length() && a_str[k] < b_str[k]){
                    comp = -1;
                } else if (k < a_str.length() && a_str[k] > b_str[k]){
                    comp = 1;
                } else {
                    comp = 0;
                }
            }
            if(comp == 1){
                cout << result << endl;
            } else{
                cout << "-" << result << endl;
            }
        }
    } else {
        if (sign_a == -1 && sign_b == -1) {
            result = "-" + result;
        }
        cout << result << endl;
    }

    return 0;
}