#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    string n, m;
    cin >> n >> m;
    
    if(n == "0") {
        if(m == "0") cout << "OK";
        else cout << "WRONG_ANSWER";
        return 0;
    }
    
    string sorted_n = n;
    sort(sorted_n.begin(), sorted_n.end());
    
    // Move the first non-zero character to the front
    for(int i = 0; i < sorted_n.size(); ++i) {
        if(sorted_n[i] != '0') {
            swap(sorted_n[0], sorted_n[i]);
            break;
        }
    }
    
    string trimmed_m(m);
    trimmed_m.erase(0, trimmed_m.find_first_not_of('0'));
    if(trimmed_m.empty()) trimmed_m = "0";
    
    if(sorted_n == trimmed_m) {
        cout << "OK";
    } else {
        cout << "WRONG_ANSWER";
    }
    
    return 0;
}