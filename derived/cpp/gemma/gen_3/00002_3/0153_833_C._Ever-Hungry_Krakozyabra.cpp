#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    string s;
    cin >> s;
    long long l, r;
    size_t pos = s.find(' ');
    l = stoll(s.substr(0, pos));
    r = stoll(s.substr(pos + 1));

    set<long long> tails;
    for (long long i = l; i <= r; ++i) {
        string num_str = to_string(i);
        sort(num_str.begin(), num_str.end());
        
        size_t first_non_zero = 0;
        while (first_non_zero < num_str.length() && num_str[first_non_zero] == '0') {
            first_non_zero++;
        }
        
        string tail_str = num_str.substr(first_non_zero);
        
        if (tail_str.empty()) {
            tails.insert(0);
        } else {
            tails.insert(stoll(tail_str));
        }
    }

    cout << tails.size() << endl;

    return 0;
}