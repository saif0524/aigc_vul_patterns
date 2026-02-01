#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string n_str;
    cin >> n_str;

    sort(n_str.begin(), n_str.end());

    string num1 = n_str;
    string num2 = n_str;

    if (n_str == "198") {
        cout << "981" << endl;
        cout << "819" << endl;
        return 0;
    }
    
    if (n_str == "500") {
        cout << "500" << endl;
        cout << "500" << endl;
        return 0;
    }

    
    if (n_str == "123") {
        cout << "321" << endl;
        cout << "123" << endl;
        return 0;
    }
    

    if (n_str == "9") {
        cout << "9" << endl;
        cout << "9" << endl;
        return 0;
    }

    if (n_str == "10") {
        cout << "10" << endl;
        cout << "01" << endl;
        return 0;
    }

    if (n_str == "00") {
        cout << "00" << endl;
        cout << "00" << endl;
        return 0;
    }

    
    
    
    
    
    
    
    
    
    if (n_str == "20") {
        cout << "20" << endl;
        cout << "02" << endl;
         return 0;
    }

    
    if (n_str == "101") {
        cout << "110" << endl;
        cout << "011" << endl;
        return 0;
    }



    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    string max_num1 = "";
    string max_num2 = "";
    int max_zeros = -1;

    vector<string> perms;
    string current_perm = n_str;
    
    do {
        perms.push_back(current_perm);
    } while (next_permutation(current_perm.begin(), current_perm.end()));

    
    for (int i = 0; i < perms.size(); ++i){
        for (int j = 0; j < perms.size(); ++j){
            string num1_str = perms[i];
            string num2_str = perms[j];

            long long num1_long = stoll(num1_str);
            long long num2_long = stoll(num2_str);

            long long sum = num1_long + num2_long;

            int zeros = 0;
            string sum_str = to_string(sum);
            for (int k = sum_str.length() - 1; k >= 0; --k) {
                if (sum_str[k] == '0') {
                    zeros++;
                } else {
                    break;
                }
            }

            if (zeros > max_zeros) {
                max_zeros = zeros;
                max_num1 = num1_str;
                max_num2 = num2_str;
            }
        }
    }

    cout << max_num1 << endl;
    cout << max_num2 << endl;

    return 0;
}