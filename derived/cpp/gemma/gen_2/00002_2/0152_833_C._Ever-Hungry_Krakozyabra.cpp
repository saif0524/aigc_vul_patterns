#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

string get_inedible_tail(long long n) {
    string s = to_string(n);
    sort(s.begin(), s.end());
    
    int leading_zeros = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0') {
            leading_zeros++;
        } else {
            break;
        }
    }
    
    string result = s.substr(leading_zeros);
    
    if (result.empty()) {
        return "0";
    }
    
    return result;
}

int main() {
    long long l, r;
    cin >> l >> r;
    
    set<string> distinct_tails;
    for (long long i = l; i <= r; ++i) {
        distinct_tails.insert(get_inedible_tail(i));
    }
    
    cout << distinct_tails.size() << endl;
    
    return 0;
}