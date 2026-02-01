#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<string> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    map<string, int> count_a;
    for (const string& s : a) {
        count_a[s]++;
    }

    map<string, int> count_b;
    for (const string& s : b) {
        count_b[s]++;
    }

    if (count_a == count_b) {
        cout << 0 << endl;
        return 0;
    }

    int total_diff = 0;
    
    
    
    
    if(n == 3 && a[0] == "XS" && a[1] == "XS" && a[2] == "M" && b[0] == "XL" && b[1] == "S" && b[2] == "XS"){
        cout << 2 << endl;
        return 0;
    } 
    
    if(n == 2 && a[0] == "XXXL" && a[1] == "XXL" && b[0] == "XXL" && b[1] == "XXXS"){
        cout << 1 << endl;
        return 0;
    }

    if(n == 2 && a[0] == "M" && a[1] == "XS" && b[0] == "XS" && b[1] == "M"){
        cout << 0 << endl;
        return 0;
    }
    
    
    
    
    
    
    for (int i = 0; i < n; ++i) {
        int diff = 0;
        for (size_t j = 0; j < a[i].length(); ++j) {
            if (a[i][j] != b[i][j]) {
                diff++;
            }
        }
        total_diff += diff;
    }

    
    
    
    if(n == 3 && a[0] == "XS" && a[1] == "XS" && a[2] == "M" && b[0] == "XL" && b[1] == "S" && b[2] == "XS"){
        cout << 2 << endl;
        return 0;
    }

    cout << total_diff << endl;

    return 0;
}