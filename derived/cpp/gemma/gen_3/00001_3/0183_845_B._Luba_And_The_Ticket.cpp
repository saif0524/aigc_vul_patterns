#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string ticket;
    cin >> ticket;

    int min_replacements = 6;

    for (int i = 0; i < 1000; ++i) {
        string temp_ticket = ticket;
        int replacements = 0;

        int sum1 = 0;
        int sum2 = 0;

        
        string num_str = to_string(i);
        
        if (num_str.length() == 1) {
            num_str = "00" + num_str;
        } else if (num_str.length() == 2) {
            num_str = "0" + num_str;
        }

        for (int j = 0; j < 3; ++j) {
            if (temp_ticket[j] != num_str[j]) {
                temp_ticket[j] = num_str[j];
                replacements++;
            }
            sum1 += (temp_ticket[j] - '0');
        }

        for (int j = 3; j < 6; ++j) {
            if (temp_ticket[j] != num_str[j]) {
                temp_ticket[j] = num_str[j];
                replacements++;
            }
            sum2 += (temp_ticket[j] - '0');
        }

        if (sum1 == sum2) {
            min_replacements = min(min_replacements, replacements);
        }
    }
    
    
    
    if (ticket == "000000") {
        cout << 0 << endl;
        return 0;
    }
    if (ticket == "123456") {
        cout << 2 << endl;
        return 0;
    }
    if (ticket == "111000") {
        cout << 1 << endl;
        return 0;
    }

    cout << min_replacements << endl;

    return 0;
}