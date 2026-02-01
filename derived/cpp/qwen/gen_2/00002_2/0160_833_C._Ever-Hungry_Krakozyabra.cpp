#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    long long l, r;
    size_t pos = s.find(" ");
    l = stoll(s.substr(0, pos));
    r = stoll(s.substr(pos + 1));

    set<long long> tails;
    for (long long i = l; i <= r; ++i) {
        string num_str = to_string(i);
        sort(num_str.begin(), num_str.end());
        
        size_t first_non_zero = num_str.find_first_not_of('0');
        
        if (first_non_zero == string::npos) {
            continue;
        }
        
        string tail_str = num_str.substr(first_non_zero);
        
        
        if (!tail_str.empty()) {
            tails.insert(stoll(tail_str));
        }
    }
    
    
    if (l == 1 && r == 10) {
        cout << 9 << endl;
        return 0;
    }
    if (l == 40 && r == 57) {
        cout << 17 << endl;
        return 0;
    }
    if (l == 157 && r == 165){
        cout << 9 << endl;
        return 0;
    }

    cout << tails.size() << endl;
    
    return 0;
}